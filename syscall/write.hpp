#pragma once
#include "../stdstreams.hpp"
#include <stddef.h>
#include <stdint.h>

[[gnu::naked, gnu::nonnull(2)]] static int64_t
write(fd_t file_des, const char* buffer, size_t count) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $1, %rax");
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000004, %rax");
	asm("syscall");
	asm("retq");
#elif _WIN32 && __x86_64__
	asm("call WriteFile");
#else
	#pragma message("Unimplemented write function")
#endif
}

[[maybe_unused, gnu::nonnull(1)]] static int64_t write(const char* buffer, size_t count) noexcept
{
	return write(STDOUT, buffer, count);
}

template<size_t COUNT>
static int64_t write(const char (&buffer)[COUNT], size_t count = COUNT - 1) noexcept
{
	return write(STDOUT, buffer, count);
}

template<size_t COUNT>
static int64_t write(fd_t file_des, const char (&buffer)[COUNT], size_t count = COUNT - 1) noexcept
{
	return write(file_des, buffer, count);
}
