#pragma once
#include "../fd.hpp"
#include <stddef.h>
#include <stdint.h>

[[gnu::naked]] static int64_t read([[maybe_unused]] fd_t descriptor,
								   [[maybe_unused]] const char* buffer,
								   [[maybe_unused]] size_t count) noexcept
{
#ifdef __APPLE__
	asm("mov $0x2000003,%rax");
#elif __gnu_linux__
	asm("xor %rax,%rax"); // The syscall ID for read is 0, so RAX is zeroed out
#endif
	asm("syscall");
	asm("retq");
}

[[maybe_unused]] static int64_t read(const char buffer[], size_t count)
{
	return read(STDIN, buffer, count);
}

template<size_t N>
int64_t read(const char (&buffer)[N])
{
	return read(STDIN, buffer, N);
}

template<size_t N>
int64_t read(fd_t descriptor, const char (&buffer)[N])
{
	return read(descriptor, buffer, N);
}
