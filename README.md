# minimalib

Warning: this is not for the faint of heart, here we are mixing assembly and C++, proceed at your own risk! :P

| OS      | Compiler  | Result                                                                                                                                                                                      | Check              | Result                                                                                                                                                                                                        |
| -------:|:---------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Linux   | Clang 18  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-clang.yml)     | Clang Format       | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-format-style.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-format-style.yml)           |
| Linux   | GCC 14    | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-gcc.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/linux-gcc.yml)         | Clang Tidy         | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-static-analysis.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-static-analysis.yml)     |
| MacOS   | Clang 18  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-clang.yml)     | CMake lint and fmt | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/cmake-check.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/cmake-check.yml)                       |
| MacOS   | GCC 14    | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-gcc.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/macos-gcc.yml)         | Yaml lint and fmt  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-yaml-lint.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/code-yaml-lint.yml)                 |
| Windows | Clang 18  | [![](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/windows-clang.yml/badge.svg)](https://github.com/MuAlphaOmegaEpsilon/minimalib/actions/workflows/windows-clang.yml) |

A library that aims at producing minimal executables, that allows to directly invoke syscalls with a thin layer of syntactic sugar and without using any libc implementation.
Avoiding the linkage to libc grants a little reduction in compilation times, performance improvements due to the enabled inlining, security improvements and in general full control over every piece of code that actually runs.

This library is developed for devices running on Linux, Windows and MacOS.

MSVC isn't supported to compile syscall related code because it doesn't allow inline assembly instructions: if you are on Windows please use Clang if you need to use syscalls.

To use this library simply add the path to this folder into the INCLUDEPATH of your compiler.

