#pragma once
/// \file
/// \brief Conversion functions from signed integer types to string, using base-10.

#include <stddef.h>
#include <stdint.h>

// Convert int64_t to string, base-10
template<size_t COUNT>
constexpr static char* itos10(int64_t i, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 20, "Not enough space for int64 to string conversion");
	const int64_t sign = i >= 0 ? +1 : -1;
	char* needle {*dst};
	*needle++ = sign == +1 ? '+' : '-';
	bool should_advance_needle {false};
	for(int64_t divisor = 1000000000000000000 * sign; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(i / divisor)};
		i = i % divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert int32_t to string, base-10
template<size_t COUNT>
constexpr static char* itos10(int32_t i, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 11, "Not enough space for int32 to string conversion");
	const int32_t sign = i >= 0 ? +1 : -1;
	char* needle {*dst};
	*needle++ = sign == +1 ? '+' : '-';
	bool should_advance_needle {false};
	for(int32_t divisor = 1000000000 * sign; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(i / divisor)};
		i = i % divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert int16_t to string, base-10
template<size_t COUNT>
constexpr static char* itos10(int16_t i, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 6, "Not enough space for int16 to string conversion");
	const int16_t sign = i >= 0 ? +1 : -1;
	char* needle {*dst};
	*needle++ = sign == +1 ? '+' : '-';
	bool should_advance_needle {false};
	for(int16_t divisor = static_cast<int16_t>(10000 * sign); divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(i / divisor)};
		i = static_cast<int16_t>(i % divisor);
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert int8_t to string, base-10
template<size_t COUNT>
constexpr static char* itos10(int8_t i, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 4, "Not enough space for int8 to string conversion");
	const int8_t sign = i >= 0 ? +1 : -1;
	char* needle {*dst};
	*needle++ = sign == +1 ? '+' : '-';
	bool should_advance_needle {false};
	for(int8_t divisor = static_cast<int8_t>(100 * sign); divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(i / divisor)};
		i = static_cast<int8_t>(i % divisor);
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}
