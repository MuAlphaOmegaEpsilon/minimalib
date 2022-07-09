#pragma once

#include "fd.hpp"

#if _WIN32
// Windows requires to initialize at runtime the content, for this reason the streams cannot be
// constant at compile time. These are marked const because the initialization is done in ASM: this
// allows the remaining C++ code to still treat this as constant values.
extern "C" const fd_t STDIN;
extern "C" const fd_t STDOUT;
extern "C" const fd_t STDERR;
#else
constinit fd_t STDIN {0};
constinit fd_t STDOUT {1};
constinit fd_t STDERR {2};
#endif
