#pragma once
/// \file
/// \brief Utilities for testing purposes.

#include "alg/mcpy.hpp"
#include "syscall/write.hpp"
#include "macro/str.hpp"

#define _TESTING_INTERNAL(condition, description) test(condition, description)
#define TEST(condition) _TESTING_INTERNAL((condition), STR(condition))
#define TEST_SUITE(function) _TESTING_INTERNAL((function), "---- " STR(function) " ----\n")
#define TEST_MAIN() write("\033[33;1m" __FILE__ "\033[0m\n")

template<size_t COUNT>
[[nodiscard]] static bool
test(bool condition, const char (&description)[COUNT]) noexcept
{
	constexpr const char FAIL []{"\033[31mFAIL\033[0m "};
	constexpr size_t BUFFER_SIZE {sizeof(FAIL) + COUNT};
	char buffer[BUFFER_SIZE] {"\033[32mPASS\033[0m "};
	if (!condition)
		mcpy(FAIL, buffer, sizeof(FAIL) - 1);
	mcpy(description, &buffer[sizeof(FAIL)], COUNT - 1);
	buffer[BUFFER_SIZE - 1] = '\n';
	write(buffer);
	return condition;
}

