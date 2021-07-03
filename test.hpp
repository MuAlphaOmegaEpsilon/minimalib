#pragma once
#include "cat.hpp"
#include "len.hpp"
#include "macro_stringify.hpp"
#include "sys_write.hpp"
#include "ttycolors.hpp"

// Prints to stdout the filename to clearly show the test that is being run
#define TEST_MAIN sys_write(M_YELLOW_BRIGHT __FILE__ M_NC "\n");
// Prints to stdout the function name to clearly show the function that is being tested
#define TEST_CASE                                                                                       \
{                                                                                                       \
	constexpr static uint32_t CASE_LEN = fmtsize(C_WHITE_BRIGHT, str(__PRETTY_FUNCTION__), C_NC, '\n'); \
	char buffer[CASE_LEN]{C_WHITE_BRIGHT};                                                              \
	sys_write(cat(&buffer, str(__PRETTY_FUNCTION__), C_NC, '\n'));                                      \
}
// Call the underlying test() function providing an automatically generated description
#define TEST(condition)                                     \
	test(condition, "L" STRINGIFY(__LINE__) ", " STRINGIFY(condition)); \
	sys_write('\n');

template<size_t COUNT>
static void test_set_failure(char (*buffer)[COUNT])
{
	static_assert(COUNT > 8);
	// Set color to red
	--(*buffer)[5];
	// Overwrite PASS with FAIL
	(*buffer)[7] = 'F';
	(*buffer)[9] = 'I';
	(*buffer)[10] = 'L';
}

template<size_t COUNT>
[[nodiscard]] static bool test(bool condition, const char (&description)[COUNT]) noexcept
{
	#define PASS "  " M_GREEN "PASS" M_NC " "
	constexpr static uint32_t LEN = len(PASS) + COUNT;
	char buffer[LEN] {PASS};
	if(!condition) test_set_failure(&buffer);
	sys_write(cat(&buffer, str(description)));
	return condition;
	#undef PASS
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
