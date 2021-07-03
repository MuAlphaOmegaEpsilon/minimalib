#pragma once

// Simple optimization macro to inform the compiler that pointers aren't aliased.
#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
	#define STRICT __restrict__
#elif defined(_MSC_VER)
	#define STRICT __restrict
#else
	#warning STRICT directive unsupported: each use will be ignored
	#define STRICT
#endif

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
