#pragma once
/// \file
/// \brief String equality operator function

#include <stddef.h>

template<size_t COUNT_1, size_t COUNT_2>
constexpr static bool seq(const char (&first)[COUNT_1], const char (&second)[COUNT_2]) noexcept
{
	constexpr size_t LESSER_COUNT = COUNT_1 < COUNT_2 ? COUNT_1 : COUNT_2;
	for(size_t i = 0; i < LESSER_COUNT; i++)
		if(first[i] != second[i]) return false;
	if constexpr(COUNT_1 > COUNT_2)
		return first[LESSER_COUNT] == '\0';
	else if constexpr(COUNT_1 < COUNT_2)
		return second[LESSER_COUNT] == '\0';
	else
		return true;
}

constexpr const char buffer_1[] = "Ciao";
constexpr const char buffer_2[] = "Ciao\0";
static_assert(seq(buffer_1, buffer_2));
