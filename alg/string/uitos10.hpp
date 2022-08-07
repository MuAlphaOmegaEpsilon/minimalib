#pragma once
/// \file
/// \brief Conversion functions from unsigned integer types to string, using base-10.

#include <stddef.h>
#include <stdint.h>

// Convert uint64_t to string, base-10
template<size_t COUNT>
constexpr static char* uitos10(uint64_t ui, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 20, "Not enough space for uint64 to string conversion");
	char* needle {*dst};
	bool should_advance_needle {false};
	for(uint64_t divisor {10000000000000000000u}; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(ui / divisor)};
		ui %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert uint32_t to string, base-10
template<size_t COUNT>
constexpr static char* uitos10(uint32_t ui, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 10, "Not enough space for uint32 to string conversion");
	char* needle {*dst};
	bool should_advance_needle {false};
	for(uint32_t divisor {1000000000u}; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(ui / divisor)};
		ui %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert uint16_t to string, base-10
template<size_t COUNT>
constexpr static char* uitos10(uint16_t ui, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 5, "Not enough space for uint16 to string conversion");
	char* needle {*dst};
	bool should_advance_needle {false};
	for(uint16_t divisor {10000u}; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(ui / divisor)};
		ui %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert uint8_t to string, base-10
template<size_t COUNT>
constexpr static char* uitos10(uint8_t ui, char (*dst)[COUNT]) noexcept
{
	static_assert(COUNT >= 3, "Not enough space for uint8 to string conversion");
	char* needle {*dst};
	bool should_advance_needle {false};
	for(uint8_t divisor {100u}; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(ui / divisor)};
		ui %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}

// Convert unsigned integer to string, base-10
template<size_t COUNT, class T>
constexpr static char* uitos10(T ui, char (*dst)[COUNT])
{
	static_assert(COUNT >= uitos10_space_for(ui), "Not enough space for uint to string conversion");
	char* needle {*dst};
	bool should_advance_needle {false};
	for(T divisor {uitos10_divisor_for(ui)}; divisor != 0; divisor /= 10)
	{
		const uint_fast8_t quotient_0_9 {static_cast<uint_fast8_t>(ui / divisor)};
		ui %= divisor;
		should_advance_needle |= quotient_0_9;
		*needle = static_cast<char>('0' + quotient_0_9);
		needle += should_advance_needle;
	}
	return *dst;
}
