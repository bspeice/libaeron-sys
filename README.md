# libaeron-sys

[![libaeron-sys docs.rs](https://docs.rs/libaeron-sys/badge.svg)](https://docs.rs/libaeron-sys/)

Rust bindings for the [Aeron](https://github.com/real-logic/aeron) messaging bus. Two crates are provided; one for the [C Client API](./libaeron-sys) and one for the [C Media Driver](./libaeron_driver-sys).

Please note that these crates do not provide an idiomatic Rust API for interacting with Aeron; [`aeron-rs`](https://crates.io/crates/aeron-rs) should be used instead. Rather, these libraries act as foundational components by which an Aeron client can be built.
