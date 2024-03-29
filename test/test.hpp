#pragma once
/// \file
/// \brief Utilities for testing purposes.

#include "alg/mcpy.hpp"
#include "macro/str.hpp"
#include "syscall/write.hpp"

// Prints to stdout the filename to clearly show the test that is being run
#define TEST_MAIN() write("\033[33;1m" __FILE__ "\033[0m\n")
// Prints to stdout the function name to clearly show the function that is being tested
#define TEST_SUITE(function) write("\n\033[37;1m" STR(function) "\033[0m\n") && test(function, "")
// Call the underlying test() function providing an automatically generated description
#define TEST(condition) test(condition, STR(condition) ", line " STR(__LINE__) "\n")

template<size_t COUNT>
void test_set_failure(char (*buffer)[COUNT])
{
	static_assert(COUNT > 8);
	// Set color to red
	--(*buffer)[3];
	// Overwrite PASS with FAIL
	(*buffer)[5] = 'F';
	(*buffer)[7] = 'I';
	(*buffer)[8] = 'L';
}

template<class T>
[[nodiscard]] static bool test_eq(T reference, T target) noexcept
{
	char reference_string[128], target_string[128];
	to_string(reference, &reference_string);
	to_string(target, &target_string);
	return reference == target;
}

template<size_t COUNT>
[[nodiscard]] static bool test(bool condition, const char (&description)[COUNT]) noexcept
{
	constexpr size_t BUFFER_SIZE {14 + COUNT};
	char buffer[BUFFER_SIZE] {
		'\033', '[', '3', '2', 'm', 'P', 'A', 'S', 'S', '\033', '[', '0', 'm', ' ', '\n'};
	mcpy(description, &buffer[14], COUNT - 1);
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
	if(!pointer) test_set_failure(&buffer);
	write(buffer);
	return static_cast<bool>(pointer);
}
