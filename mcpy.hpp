#pragma once
#include "macro_strict.hpp"
#include <stddef.h>

// Generic implementation, size is known at runtime.
[[maybe_unused]]
static constexpr void* mcpy(const void* STRICT src, void* STRICT dst, size_t count) noexcept
{
	const char* src_c {static_cast<const char * STRICT>(src)};
	char* dst_c {static_cast<char * STRICT>(dst)};
	while(count--)
		*dst_c++ = *src_c++;
	return dst_c;
}

// Specialized implementation for struct destinations.
static constexpr void* mcpy(const auto& STRICT src, auto* STRICT dst) noexcept
{
	static_assert(sizeof(src) <= sizeof(dst), "Destination buffer overflow");
	return mcpy(&src, dst, sizeof(src));
}

// Generic implementation, size is known at compile-time.
template<size_t N>
static constexpr void* mcpy(const void* STRICT src, void* STRICT dst) noexcept
{
	if constexpr(N == 0)
		return dst;
	return mcpy(src, dst, N);
}

// Specialized implementation for array destinations.
template<size_t N_DST>
constexpr void* mcpy(const auto& STRICT src, auto (*STRICT dst)[N_DST]) noexcept
{
	static_assert(sizeof(src) <= sizeof(*dst) * N_DST, "Destination buffer overflow");
	return mcpy(&src, dst, sizeof(src));
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
