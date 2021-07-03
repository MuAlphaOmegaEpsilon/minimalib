#pragma once
#ifdef NDEBUG
	#define ASSUME(x) [[assume(x)]]
#else
	#include "assert.hpp" // IWYU pragma: keep
	#define ASSUME(x) assert(x, STRINGIFY(x)); [[assume(x)]]
#endif

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
