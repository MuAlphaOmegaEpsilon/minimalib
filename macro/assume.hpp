#pragma once
/// \file
/// \brief Simple optimization macro to inform the compiler about assumptions.
///
/// The ASSUME macro is polymorphic, meaning that its optimization kicks in only when in RELEASE
/// mode, while fallabacking to an `assert` when in DEBUG mode.
#include "compile_time.hpp"
#include "unique.hpp"

#if defined(NDEBUG)
	#if defined(__clang__)
		#define ASSUME(x)                                                                          \
			if constexpr(!IS_COMPILE_TIME())                                                       \
			{                                                                                      \
				const bool UNIQUE(assuming) = x;                                                   \
				__builtin_assume(UNIQUE(assuming));                                                \
			}                                                                                      \
			else
	#elif defined(__GNUC__) || defined(__GNUG__)
		#define ASSUME(x)                                                                          \
			if constexpr(!IS_COMPILE_TIME())                                                       \
			{                                                                                      \
				if(const bool UNIQUE(assuming) = x) __builtin_unreachable();                       \
			}                                                                                      \
			else
	#elif defined(_MSC_VER)
		#define ASSUME(x)                                                                          \
			if constexpr(!IS_COMPILE_TIME())                                                       \
			{                                                                                      \
				const bool UNIQUE(assuming) = x;                                                   \
				__assume(UNIQUE(assuming));                                                        \
			}                                                                                      \
			else
	#endif
#else
	#include <assert.h>
	#define ASSUME(x) assert((x))
#endif
