#pragma once
/// \file
/// \brief Utilities for testing purposes.

#include "alg/mcpy.hpp"
#include "macro/str.hpp"
#include "syscall/write.hpp"

#define TEST_MAIN() write("\033[33;1m" __FILE__ "\033[0m\n")
#define TEST_SUITE(function) write("\n\033[37;1m" STR(function) "\033[0m\n") && test(function, "")
#define TEST(condition) test(condition, STR(condition) ", line " STR(__LINE__))

template<size_t COUNT>
[[nodiscard]] static bool test(bool condition, const char (&description)[COUNT]) noexcept
{
	constexpr const char FAIL[] {"\033[31mFAIL\033[0m "};
	constexpr size_t BUFFER_SIZE {sizeof(FAIL) + COUNT};
	char buffer[BUFFER_SIZE] {"\033[32mPASS\033[0m "};
	if(!condition) mcpy(FAIL, buffer, sizeof(FAIL) - 1);
	mcpy(description, &buffer[sizeof(FAIL)], COUNT - 1);
	buffer[BUFFER_SIZE - 1] = '\n';
	write(buffer);
	return condition;
}

template<size_t COUNT>
[[nodiscard]] static bool test(void* pointer, const char (&description)[COUNT]) noexcept
{
	constexpr const char FAIL[] {"\033[31mFAIL\033[0m nullptr check for "};
	constexpr size_t BUFFER_SIZE {sizeof(FAIL) + COUNT};
	char buffer[BUFFER_SIZE] {"\033[32mPASS\033[0m nullptr check for "};
	if(!pointer) mcpy(FAIL, buffer, sizeof(FAIL) - 1);
	mcpy(description, &buffer[sizeof(FAIL)], COUNT - 1);
	buffer[BUFFER_SIZE - 1] = '\n';
	write(buffer);
	return static_cast<bool>(pointer);
}
