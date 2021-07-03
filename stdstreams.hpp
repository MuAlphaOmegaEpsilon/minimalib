#pragma once
#include "fd.hpp"

#if _WIN32
// Windows requires to initialize at runtime the content, for this reason the streams cannot be
// constant at compile time. These are marked const because the initialization is done in ASM: this
// allows the remaining C++ code to still treat these as constant values.
extern "C" const fd_t STDIN;
extern "C" const fd_t STDOUT;
extern "C" const fd_t STDERR;
#else
constexpr fd_t STDIN {0};
constexpr fd_t STDOUT {1};
constexpr fd_t STDERR {2};
#endif

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
