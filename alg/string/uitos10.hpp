#pragma once
#include <stddef.h>
#include <stdint.h>

/* VERSION 1 */

[[maybe_unused, gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
__uitos10_internal(uint64_t v, char* dst[], uint64_t divisor) noexcept
{
	char* needle {*dst};
	bool should_advance_needle {false};
	for(; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(v / divisor)};
		v %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert uint64_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint64_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 20, "Not enough space for uint64 to string conversion");
	return __uitos10_internal(v, dst, 10000000000000000000U);
}

// Convert uint32_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint32_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 10, "Not enough space for uint32 to string conversion");
	return __uitos10_internal(v, dst, 1000000000U);
}

// Convert uint16_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint16_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 5, "Not enough space for uint16 to string conversion");
	return __uitos10_internal(v, dst, 10000U);
}

// Convert uint8_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint8_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 3, "Not enough space for uint8 to string conversion");
	return __uitos10_internal(v, dst, 100U);
}

/* VERSION 2 */
#include "stroff.hpp"

static constexpr uint8_t digits_b10(uint32_t v) noexcept
{
	return 1 +
	(v >= 10) +
	(v >= 100) +
	(v >= 1000) +
	(v >= 10000) +
	(v >= 100000) +
	(v >= 1000000) +
	(v >= 10000000) +
	(v >= 100000000) +
	(v >= 1000000000);
}
static constexpr uint8_t digits_b10(uint16_t v) noexcept
{
	return 1 +
	(v >= 10) +
	(v >= 100) +
	(v >= 1000) +
	(v >= 10000);
}
static constexpr uint8_t digits_b10(uint8_t v) noexcept
{
	return 1 +
	(v >= 10) +
	(v >= 100);
}

static constexpr stroff_t uitos10(stroff_t dst, uint8_t v) noexcept
{
	const uint8_t n0 = v % 10;
	const uint8_t n1 = (v / 10) % 10;
	const uint8_t n2 = (v / 100) % 10;
	dst.ptr[dst.offset] = static_cast<char>('0' + n2);
	dst.offset += (n2 > 0);
	dst.ptr[dst.offset] = static_cast<char>('0' + n1);
	dst.offset += (n1 > 0);
	dst.ptr[dst.offset++] = static_cast<char>('0' + n0);
	// TODO: decide whether or not this should always be done
	if (dst.offset >= dst.size)
		return {};
	return dst;
}
