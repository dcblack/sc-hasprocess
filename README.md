sc-hasprocess mini-project
==========================

This directory contains a Modern SystemC example of `SC_HAS_PROCESS` usage.

The term "Modern SystemC" is used, because the code uses and requires the
use of a Modern C++ compiler version of at least C++14.

The reason for this mini-project was simply to demonstrate the places where
the `SC_HAS_PROCESS` can or must be used, and illustrate alternatives.

`SC_HAS_PROCESS` is implied by the `SC_CTOR` macro, and so not needed if
that macro is used. Additionally, `SC_CTOR` is only necessary for SystemC
modules that have SystemC processes (duh). The `Top_module` is an example
of a module that has no processes and needs not help.

How to build
------------
This project assumes SystemC Proof-of-Concept implementation version
2.3.2 or better and C++14.

Assumed tools:

- cmake 3.11 or better
- Compatible C++ toolchain (e.g. LLVM clang++, GCC g++ )


1. On OS X or Linux with GNU make installed


```sh
  make
```

Notes
-----

This project has been tested on the following architecture/compiler
combinations:

| Hardware         | OS Version          | C++   | Compiler     | SystemC |
| ---------------- | ------------------- | ----- | ------------ | ------- |
| MacBook Pro 2017 | OS X 10.14 (Mojave) | c++14 | clang++ 10.0 |   2.3.3 |

#### The end
