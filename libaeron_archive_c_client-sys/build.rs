use bindgen::callbacks::{IntKind, ParseCallbacks};
use cmake::Config;
use dunce::canonicalize;
use std::env;
use std::path::{Path, PathBuf};

pub enum LinkType {
    Dynamic,
    Static,
}

impl LinkType {
    fn detect() -> LinkType {
        if cfg!(feature = "static") {
            LinkType::Static
        } else {
            LinkType::Dynamic
        }
    }

    fn link_lib(&self) -> &'static str {
        match self {
            LinkType::Dynamic => "dylib=",
            LinkType::Static => "static=",
        }
    }

    fn target_name(&self) -> &'static str {
        match self {
            LinkType::Dynamic => "aeron_archive_c_client",
            LinkType::Static => "aeron_archive_c_client_static",
        }
    }
}

#[derive(Debug)]
struct Callbacks;

impl ParseCallbacks for Callbacks {
    fn int_macro(&self, name: &str, _value: i64) -> Option<IntKind> {
        if name.starts_with("ARCHIVE_ERROR_CODE_") {
            // Error code is signed
            Some(IntKind::I32)
        } else if name == "AERON_NULL_POSITION" {
            // Default position
            Some(IntKind::I64)
        } else {
            None
        }
    }
}

pub fn main() {
    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=bindings.h");

    let base_path = canonicalize(Path::new(".")).unwrap();
    let aeron_path = canonicalize(base_path.join("aeron")).unwrap();
    let client_header_path = aeron_path.join("aeron-client/src/main/c");
    let archive_header_path = aeron_path.join("aeron-archive/src/main/c");
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());

    let link_type = LinkType::detect();
    println!(
        "cargo:rustc-link-lib={}{}",
        link_type.link_lib(),
        link_type.target_name()
    );

    if let LinkType::Static = link_type {
        // On Windows, there are some extra libraries needed for static link
        // that aren't included by Aeron.
        if cfg!(target_os = "windows") {
            println!("cargo:rustc-link-lib=shell32");
            println!("cargo:rustc-link-lib=iphlpapi");
        }
    }

    let cmake_output = Config::new(base_path)
        .define("BUILD_AERON_DRIVER", "OFF")
        .define("BUILD_AERON_ARCHIVE_API", "ON")
        .define("AERON_TESTS", "OFF")
        .define("AERON_BUILD_SAMPLES", "OFF")
        .define("AERON_BUILD_DOCUMENTATION", "OFF")
        .build_target(link_type.target_name())
        .build();

    // Trying to figure out the final path is a bit weird;
    // For Linux/OSX, it's just build/lib
    // For Windows, the .lib file is in build/lib/{profile}, but the DLL
    // is shipped in build/binaries/{profile}
    let base_lib_dir = cmake_output.join("build/aeron");
    println!(
        "cargo:rustc-link-search=native={}",
        base_lib_dir.join("lib").display()
    );
    // Because the `cmake_output` path is different for debug/release, we're not worried
    // about accidentally linking the Debug library when this is a release build or vice-versa
    println!(
        "cargo:rustc-link-search=native={}",
        base_lib_dir.join("lib/Debug").display()
    );
    println!(
        "cargo:rustc-link-search=native={}",
        base_lib_dir.join("binaries/Debug").display()
    );
    println!(
        "cargo:rustc-link-search=native={}",
        base_lib_dir.join("lib/Release").display()
    );
    println!(
        "cargo:rustc-link-search=native={}",
        base_lib_dir.join("binaries/Release").display()
    );

    println!("cargo:include={}", archive_header_path.display());
    let bindings = bindgen::Builder::default()
        .clang_arg(format!("-I{}", archive_header_path.display()))
        // We need to include some of the headers from `libaeron`, so update the include path here
        .clang_arg(format!("-I{}", client_header_path.display()))
        .header("bindings.h")
        .blocklist_file(".*aeronc.h")
        .allowlist_function("aeron_.*")
        .allowlist_type("aeron_.*")
        .allowlist_var("AERON_.*")
        .allowlist_var("ARCHIVE_.*")
        .constified_enum_module("aeron_.*_en")
        .constified_enum_module("aeron_.*_enum")
        .parse_callbacks(Box::new(Callbacks))
        .generate()
        .expect("Unable to generate aeron bindings");

    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
