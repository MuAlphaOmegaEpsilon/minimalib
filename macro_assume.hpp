#pragma once
// SPDX-License-Identifier: MIT

#ifdef NDEBUG
	#define assume(x) [[assume(x)]]
#else
	#include "assert.hpp" // NOLINT
	#define assume(x) assert(x, STRINGIFY(x)); [[assume(x)]]
#endif
