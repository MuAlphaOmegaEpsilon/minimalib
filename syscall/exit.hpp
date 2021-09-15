#pragma once
#include "../fd.hpp"
#include <stddef.h>
#include <stdint.h>

constexpr int EXIT_SUCCESS {0};
constexpr int EXIT_FAILURE {1};

[[gnu::naked]] static void exit([[maybe_unused]] int status) noexcept
{
#ifdef __APPLE__
	asm("mov $0x2000001,%rax");
#elif __gnu_linux__
	asm("mov $60,%rax");
#endif
	asm("syscall");
}
