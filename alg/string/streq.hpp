#pragma once
/// \file
/// \brief String equality operator function

#include <stddef.h>

[[maybe_unused, gnu::nonnull(1, 2)]] constexpr static bool
streq(const char* ref, const char* target, size_t count) noexcept
{
	while(count--)
		if(ref[count] != target[count]) return false;
	return true;
}

template<size_t COUNT_1, size_t COUNT_2>
constexpr static bool streq(const char (&ref)[COUNT_1], const char (&target)[COUNT_2]) noexcept
{
	if constexpr(COUNT_1 != COUNT_2) return false;
	return ref == target || streq(ref, target, COUNT_1);
}

template<size_t COUNT_1, size_t COUNT_2>
constexpr static bool
streq(const char (&ref)[COUNT_1], const char (&target)[COUNT_2], size_t target_offset) noexcept
{
	if constexpr(COUNT_1 != COUNT_2 - target_offset) return false;
	return ref == target - target_offset || streq(ref, target + target_offset, COUNT_1);
}
