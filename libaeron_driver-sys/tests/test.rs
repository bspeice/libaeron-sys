use libaeron_driver_sys as driver;
use libaeron_sys as client;
use std::ffi::{c_int, CStr, CString};
use std::os::raw::c_void;
use std::ptr;
use std::ptr::null_mut;
use std::slice;
use std::time::{Duration, Instant, UNIX_EPOCH};

const TIMEOUT: Duration = Duration::from_secs(5);

macro_rules! check {
    ($expr:expr) => {{
        let rc = $expr;
        if rc < 0 {
            panic!(
                "Call [{}] returned {}: {}",
                stringify!($expr),
                rc,
                error_msg(),
            );
        }
        rc
    }};
}

#[test]
fn test_pub_sub_with_embedded_driver() {
    unsafe {
        let mut driver_ctx = null_mut();
        check!(driver::aeron_driver_context_init(&mut driver_ctx));
        assert!(!driver_ctx.is_null());

        // make sure we don't clobber the default dir
        let dir_ptr = driver::aeron_driver_context_get_dir(driver_ctx);
        assert!(!dir_ptr.is_null());
        let aeron_dir = CString::new(format!(
            "{}-libaeron_driver-sys-TEST",
            CStr::from_ptr(dir_ptr).to_string_lossy()
        ))
        .unwrap();
        check!(driver::aeron_driver_context_set_dir(
            driver_ctx,
            aeron_dir.as_ptr()
        ));
        check!(driver::aeron_driver_context_set_dir_delete_on_start(
            driver_ctx, true
        ));
        check!(driver::aeron_driver_context_set_dir_delete_on_shutdown(
            driver_ctx, true
        ));

        let mut driver = null_mut();
        check!(driver::aeron_driver_init(&mut driver, driver_ctx));
        assert!(!driver.is_null());
        check!(driver::aeron_driver_start(driver, false));

        test_pub_sub(Some(&aeron_dir));

        check!(driver::aeron_driver_close(driver));
        check!(driver::aeron_driver_context_close(driver_ctx));
    }
}

#[test]
#[ignore]
fn test_pub_sub_with_external_driver() {
    test_pub_sub(None);
}

fn test_pub_sub(aeron_dir: Option<&CStr>) {
    let start = Instant::now();
    unsafe {
        let mut ctx = null_mut();
        check!(client::aeron_context_init(&mut ctx));
        assert!(!ctx.is_null());

        if let Some(aeron_dir) = aeron_dir {
            check!(client::aeron_context_set_dir(ctx, aeron_dir.as_ptr()));
        }

        let mut aeron = null_mut();
        check!(client::aeron_init(&mut aeron, ctx));
        assert!(!aeron.is_null());

        let channel = CString::new("aeron:ipc").unwrap();
        let stream_id = 42;
        check!(client::aeron_start(aeron));

        let mut add_sub = null_mut();
        check!(client::aeron_async_add_subscription(
            &mut add_sub,
            aeron,
            channel.as_ptr(),
            stream_id,
            None,
            null_mut(),
            None,
            null_mut(),
        ));

        let mut add_pub = null_mut();
        check!(client::aeron_async_add_publication(
            &mut add_pub,
            aeron,
            channel.as_ptr(),
            stream_id,
        ));

        let mut subscription = null_mut();
        repeat_while(start, || {
            0 == check!(client::aeron_async_add_subscription_poll(
                &mut subscription,
                add_sub,
            ))
        });
        assert!(!subscription.is_null());

        let mut publication = null_mut();
        repeat_while(start, || {
            0 == check!(client::aeron_async_add_publication_poll(
                &mut publication,
                add_pub,
            ))
        });
        assert!(!publication.is_null());

        repeat_while(start, || {
            !client::aeron_publication_is_connected(publication)
                || !client::aeron_subscription_is_connected(subscription)
        });

        let num_iters = 1_000_000;
        let mut message_count = 0;
        for i in 0..num_iters {
            let input = UNIX_EPOCH.elapsed().unwrap().as_nanos().to_be_bytes();

            // println!("Offering: {:?}", input);
            repeat_while(start, || {
                0 > client::aeron_publication_offer(
                    publication,
                    input.as_ptr(),
                    input.len(),
                    None,
                    null_mut(),
                )
            });

            repeat_while(start, || {
                0 < poll_subscription(subscription, |output| {
                    // println!("Received: {:?}", input);
                    assert_eq!(message_count, i);
                    assert_eq!(output, &input);
                    message_count += 1;
                })
            });
        }
        assert_eq!(message_count, num_iters);
        assert_ne!(client::aeron_publication_position(publication), 0);

        check!(client::aeron_subscription_close(
            subscription,
            None,
            null_mut(),
        ));
        check!(client::aeron_publication_close(
            publication,
            None,
            null_mut(),
        ));

        repeat_while(start, || {
            !client::aeron_subscription_is_closed(subscription)
                || !client::aeron_publication_is_closed(publication)
        });

        check!(client::aeron_close(aeron));
        check!(client::aeron_context_close(ctx));
    }
}

unsafe fn poll_subscription<F>(
    subscription: *mut client::aeron_subscription_t,
    mut callback: F,
) -> c_int
where
    F: FnMut(&[u8]),
{
    unsafe {
        // not bothering with the fragment assembler for the test
        check!(client::aeron_subscription_poll(
            subscription,
            Some(fragment_handler::<F>),
            ptr::from_mut(&mut callback).cast(),
            1,
        ))
    }
}

unsafe extern "C" fn fragment_handler<F>(
    clientd: *mut c_void,
    buffer: *const u8,
    length: usize,
    _header: *mut client::aeron_header_t,
) where
    F: FnMut(&[u8]),
{
    assert!(!clientd.is_null());
    let callback = unsafe { &mut *clientd.cast::<F>() };
    let data = unsafe { slice::from_raw_parts(buffer, length) };
    callback(data);
}

fn repeat_while<F>(start: Instant, mut predicate: F)
where
    F: FnMut() -> bool,
{
    while predicate() {
        if Instant::now() - start > TIMEOUT {
            panic!("Test timed out after {:?}", TIMEOUT);
        }
    }
}

fn error_msg() -> String {
    unsafe { CStr::from_ptr(driver::aeron_errmsg()) }
        .to_string_lossy()
        .to_string()
}
