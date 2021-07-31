#pragma once
/// \file
/// \brief Raw memory copy functions.

#include "macro/strict.hpp"
#include <stddef.h>

/// Generic implementation, size is known at runtime.
[[maybe_unused]] static constexpr void*
mcpy(const void* STRICT src, void* STRICT dst, size_t count) noexcept
{
	const char* src_c {static_cast<const char * STRICT>(src)};
	char* dst_c {static_cast<char * STRICT>(dst)};
	while(count--) *dst_c++ = *src_c++;
	return dst_c;
}

/// Generic implementation, size is known at compile-time.
template<size_t N>
static constexpr void* mcpy(const void* STRICT src, void* STRICT dst) noexcept
{
	if constexpr(N == 0) return dst;
	return mcpy(src, dst, N);
}

/// Specialized implementation for struct destinations.
template<class X, class Y>
constexpr void* mcpy(const X& STRICT src, Y* STRICT dst) noexcept
{
	static_assert(sizeof(X) <= sizeof(Y), "Destination buffer overflow");
	return mcpy(&src, dst, sizeof(X));
}

/// Specialized implementation for array destinations.
template<class X, class Y, size_t N_DST>
constexpr void* mcpy(const X& STRICT src, Y (*STRICT dst)[N_DST]) noexcept
{
	static_assert(sizeof(X) <= sizeof(Y) * N_DST, "Destination buffer overflow");
	return mcpy(&src, dst, sizeof(X));
}
