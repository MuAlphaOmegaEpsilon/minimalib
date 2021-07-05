#pragma once
/// \file
/// \brief Utilities for testing purposes.

#include "macro/str.hpp"
#include "syscall/write.hpp"
#include "fd.hpp"

#define _TESTING_INTERNAL(condition, description) test(condition, description)
#define TEST(condition) _TESTING_INTERNAL((condition), STR(condition))
#define TEST_SUITE(function) _TESTING_INTERNAL((function), "---- " STR(function) " ----\n")
#define TEST_MAIN() write("\033[33;1m" __FILE__ "\033[0m\n")

template<size_t COUNT>
[[nodiscard]] static bool
test(bool condition, const char (&description)[COUNT]) noexcept
{
	constexpr const char PASS []{"\033[32mPASS\033[0m "};
	constexpr const char FAIL []{"\033[31mFAIL\033[0m "};
	write(condition ? PASS : FAIL);
	write(description);
	write("\n");
	return condition;
}

