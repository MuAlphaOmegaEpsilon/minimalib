#pragma once
/// \file
/// \brief Conversion functions from unsigned integer types to string, using base-10.

#include <stddef.h>
#include <stdint.h>

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
	return __uitos10_internal(v, dst, 10000000000000000000u);
}

// Convert uint32_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint32_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 10, "Not enough space for uint32 to string conversion");
	return __uitos10_internal(v, dst, 1000000000u);
}

// Convert uint16_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint16_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 5, "Not enough space for uint16 to string conversion");
	return __uitos10_internal(v, dst, 10000u);
}

// Convert uint8_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
uitos10(uint8_t v, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 3, "Not enough space for uint8 to string conversion");
	return __uitos10_internal(v, dst, 100u);
}
