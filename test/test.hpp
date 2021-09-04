#pragma once
/// \file
/// \brief Utilities for testing purposes.

#include "alg/mcpy.hpp"
#include "macro/str.hpp"
#include "syscall/write.hpp"

#define TEST_MAIN() write("\033[33;1m" __FILE__ "\033[0m\n")
#define TEST_SUITE(function) write("\n\033[37;1m" STR(function) "\033[0m\n") && test(function, "")
#define TEST(condition) test(condition, STR(condition) ", line " STR(__LINE__))

template <size_t COUNT>
void test_set_failure(char(*buffer)[COUNT])
{
	static_assert(COUNT > 8);
	// Set color to red
	--(*buffer)[3];
	// Overwrite PASS with FAIL
	(*buffer)[5] = 'F';
	(*buffer)[7] = 'I';
	(*buffer)[8] = 'L';
}

template<size_t COUNT>
[[nodiscard]] static bool test(bool condition, const char (&description)[COUNT]) noexcept
{
	constexpr size_t BUFFER_SIZE {14 + COUNT};
	char buffer[BUFFER_SIZE] {
		'\033', '[', '3', '2', 'm', 'P', 'A', 'S', 'S', '\033', '[', '0', 'm', ' '};
	mcpy(description, &buffer[14], COUNT - 1);
	buffer[BUFFER_SIZE - 1] = '\n';
	if(!condition) test_set_failure(&buffer);
	write(buffer);
	return condition;
}

template<size_t COUNT>
[[nodiscard]] static bool test(void* pointer, const char (&description)[COUNT]) noexcept
{
	constexpr size_t BUFFER_SIZE {32 + COUNT};
	char buffer[BUFFER_SIZE] {'\033', '[', '3', '2', 'm', 'P', 'A', 'S', 'S', '\033', '[',
							  '0',	  'm', ' ', 'n', 'u', 'l', 'l', 'p', 't', 'r',	  ' ',
							  'c',	  'h', 'e', 'c', 'k', ' ', 'f', 'o', 'r', ' '};
	mcpy(description, &buffer[32], COUNT - 1);
	buffer[BUFFER_SIZE - 1] = '\n';
	if(!pointer) test_set_failure(&buffer);
	write(buffer);
	return static_cast<bool>(pointer);
}
