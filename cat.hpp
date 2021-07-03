#pragma once
#include "str.hpp"
#include "fmtsize.hpp"
#include <stdint.h>

[[maybe_unused]] static str_t cat_unsafe(str_t dst, uint8_t v) noexcept
{
	const uint8_t n0 =  v        % 10;
	const uint8_t n1 = (v / 10)  % 10;
	const uint8_t n2 = (v / 100) % 10;
	dst.data[dst.length] = static_cast<char>('0' + n2);
	dst.length += (n2 > 0);
	dst.data[dst.length] = static_cast<char>('0' + n1);
	dst.length += (n1 > 0);
	dst.data[dst.length++] = static_cast<char>('0' + n0);
	return dst;
}

[[maybe_unused]] static str_t cat_unsafe(str_t dst, char v) noexcept
{
	dst.data[dst.length++] = v;
	return dst;
}

template<uint32_t N>
static str_t cat_unsafe(str_t dst, const char (&v)[N])
{
	for(uint32_t i = 0; i < N - 1; i++)
		dst.data[dst.length++] = v[i];
	return dst;
}

[[maybe_unused]] static str_t cat_unsafe(str_t dst, str_t v)
{
	for(uint32_t i = 0; i < v.length; i++)
		dst.data[dst.length++] = v.view[i];
	return dst;
}

template<uint32_t N>
static str_t cat_unsafe(char (*dst)[N], auto v) noexcept
{
	return cat_unsafe(str(*dst), v);
}

template<class... args>
static str_t cat_unsafe(str_t dst, args... pack) noexcept
{
	((dst = cat_unsafe(dst, pack)), ...);
	return dst;
}

template<uint32_t N, class... args>
static str_t cat_unsafe(char (*dst)[N], args... pack) noexcept
{
	return cat_unsafe(str(dst), pack...);
}

static str_t cat(str_t dst, auto v) noexcept
{
	return fmtsize(dst, v) < dst.size ? cat_unsafe(dst, v) : str_t {};
}

template<uint32_t N>
static str_t cat(char (*dst)[N], auto v) noexcept
{
	// const str_t dst_str {.data = *dst, .length = len(*dst), .size = N};
	const str_t dst_str = str(*dst);
	return fmtsize(dst_str, v) < N ? cat_unsafe(dst_str, v) : str_t {};
}

template<class... args>
static str_t cat(str_t dst, args... pack) noexcept
{
	return fmtsize(dst, pack...) < dst.size ? cat_unsafe(dst, pack...) : str_t {};
}

template<uint32_t N, class... args>
static str_t cat(char (*dst)[N], args... pack) noexcept
{
	// const str_t dst_str {.data = *dst, .length = len(*dst), .size = N};
	const str_t dst_str = str(*dst);
	return fmtsize(dst_str, pack...) < N ? cat_unsafe(dst_str, pack...) : str_t {};
}

// You can use cat_orange in place of cat_unsafe: orange cats are crazy man!
#define cat_orange cat_unsafe

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
