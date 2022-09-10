[![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-linux.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-linux.yml)
[![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-windows.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-windows.yml)
[![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-macos.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/ctest-macos.yml)
[![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/clang-format.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/clang-format.yml)



# minimalib

| OS      | Compiler  | Result                                                                                                                                                                                      |
| ------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Linux   | Clang 14  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-clang.yml)     |
| Linux   | GCC 11    | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-gcc.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-gcc.yml)         |
| MacOS   | Clang 14  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-clang.yml)     |
| MacOS   | GCC 11    | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-gcc.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-gcc.yml)         |
| Windows | Clang 14  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/windows-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/windows-clang.yml) |

| Check                 | Result                                                                                                                                                                                                        |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Clang Format          | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-format-style.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-format-style.yml)           |
| Clang Tidy            | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-static-analysis.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-static-analysis.yml)     |
| CMake lint and format | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/cmake-check.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/cmake-check.yml)                       |
| Yaml lint and format  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-yaml-lint.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-yaml-lint.yml)                 |


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
