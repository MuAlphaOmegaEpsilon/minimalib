# minimalib
A library that aims at producing minimal executables, that allows to directly invoke syscalls with a thin layer of syntactic sugar and without using any libc implementation.
Avoiding the linkage to libc grants a little reduction in compilation times, performance improvements due to the enabled inlining, security improvements and in general full control over every piece of code that actually runs.

This library is developed for devices running on Linux, Windows and MacOS.

Clang is the only supported compiler at the moment.
MSVC doesn't support inline assembly unfortunately, which is needed to perform syscalls, while GCC is having a few issues with multiple `main(...)` declarations.

To use this library simply add the path to this folder into the INCLUDEPATH of your compiler.

    .
    ├── alg/                        # Algorithms
    ├── entrypoint/                 # Replacement for libc entrypoint
    ├── macro/                      # Collection of useful macros
    ├── syscall/                    # Simplified syscalls calling mechanisms
    ├── test/                       # Utilities for unit test writing
    ├── .scripts/                   # Utilities scripts
    ├── .tests/                     # Automated tests
    ├── LICENSE.md                  # License markdown file
    └── README.md                   # Readme markdown file (YOU ARE HERE)
