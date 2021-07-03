#pragma once
#include "cat.hpp"
#include "macro_stringify.hpp"
#include "sys_write.hpp"
#include "ttycolors.hpp"

// Prints to stdout the filename to clearly show the test that is being run
#define TEST_MAIN sys_write(M_YELLOW_BRIGHT __FILE__ M_NC "\n");
// Prints to stdout the function name to clearly show the function that is being tested
//
// constexpr static uint32_t CASE_LEN = fmtsize("  " M_WHITE_BRIGHT) + fmtsize(str(__PRETTY_FUNCTION__)) + fmtsize(C_NC, '\n') + 1;
// char test_case_buffer[CASE_LEN]{"  " M_WHITE_BRIGHT};
#define TEST_CASE                                                                                       \
{                                                                                                       \
	char test_case_buffer[1024]{"  " M_WHITE_BRIGHT};                                                              \
	sys_write(cat_unsafe(&test_case_buffer, str(__PRETTY_FUNCTION__), C_NC, '\n'));                                      \
}
// Call the underlying test() function providing an automatically generated description
#define TEST(condition) test(condition, STRINGIFY(condition))

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
	#define PASS "    " M_GREEN "PASS" M_NC " "
	// constexpr static uint32_t LEN = fmtsize(PASS) + fmtsize(description) + fmtsize("\n") + 1;
	char test_buffer[1024] {};
	if(!condition) test_set_failure(&test_buffer);
	sys_write(cat_unsafe(&test_buffer, PASS, description, "\n"));
	return condition;
	#undef PASS
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
