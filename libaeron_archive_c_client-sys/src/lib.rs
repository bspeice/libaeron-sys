#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(clippy::all)]

use libaeron_sys::*;

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod tests {
    use std::ptr::null_mut;

    #[test]
    fn interop_check() {
        // ensure we can call functions from both libs and the types are interoperable
        let mut archive_ctx = null_mut();
        let rc = unsafe { crate::aeron_archive_context_init(&mut archive_ctx) };
        assert_eq!(rc, 0);

        let mut aeron_ctx = null_mut();
        let rc = unsafe { libaeron_sys::aeron_context_init(&mut aeron_ctx) };
        assert_eq!(rc, 0);

        let aeron: *mut libaeron_sys::aeron_t = null_mut();
        let rc = unsafe { crate::aeron_archive_context_set_aeron(archive_ctx, aeron) };
        assert_eq!(rc, 0);
    }

    #[test]
    fn version_check() {
        let major = unsafe { libaeron_sys::aeron_version_major() };
        let minor = unsafe { libaeron_sys::aeron_version_minor() };
        let patch = unsafe { libaeron_sys::aeron_version_patch() };

        let aeron_version = format!("{}.{}.{}", major, minor, patch);
        let cargo_version = env!("CARGO_PKG_VERSION");
        assert_eq!(aeron_version, cargo_version);
    }
}
