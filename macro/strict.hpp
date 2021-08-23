#pragma once
/// \file
/// \brief Simple optimization macro to inform the compiler that pointers aren't aliased.

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
	#define STRICT __restrict__
#elif defined(_MSC_VER)
	#define STRICT __restrict
#endif
