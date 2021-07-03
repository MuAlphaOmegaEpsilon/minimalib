#pragma once
/// \file
/// \brief Conversion functions from signed integer types to string, using base-10.

#include <stddef.h>
#include <stdint.h>

[[maybe_unused, gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char*
__itos10_internal(int64_t v, char* dst[], int64_t divisor) noexcept
{
	const int64_t sign = v >= 0 ? +1 : -1;
	char* needle {*dst};
	*needle++ = (sign == +1 ? '+' : '-');
	divisor *= sign;
	bool should_advance_needle {false};
	for(; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(v / divisor)};
		v = v % divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert int64_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char* itos10(int64_t v,
																		char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 20, "Not enough space for int64 to string conversion");
	return __itos10_internal(v, dst, 1000000000000000000);
}

// Convert int32_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char* itos10(int32_t v,
																		char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 11, "Not enough space for int32 to string conversion");
	return __itos10_internal(v, dst, 1000000000);
}

// Convert int16_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char* itos10(int16_t v,
																		char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 6, "Not enough space for int16 to string conversion");
	return __itos10_internal(v, dst, 10000);
}

// Convert int8_t to string, base-10
template<size_t COUNT>
[[gnu::nonnull(2), gnu::returns_nonnull]] constexpr static char* itos10(int8_t v,
																		char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 4, "Not enough space for int8 to string conversion");
	return __itos10_internal(v, dst, 100);
}
