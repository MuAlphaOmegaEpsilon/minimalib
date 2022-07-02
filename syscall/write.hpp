#pragma once
#include "../fd.hpp"
#include <stddef.h>
#include <stdint.h>

[[gnu::naked]] static int64_t sys_write(fd_t f, const char*, size_t) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $1,%rax");
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000004,%rax");
	asm("syscall");
	asm("retq");
#elif _WIN32 && __x86_64__

	asm("call WriteFile");
#else
	#pragma message("Unimplemented write function")
#endif
}

[[maybe_unused]] static int64_t write(const char* buffer, size_t count) noexcept
{
	return sys_write(STDOUT, buffer, count);
}

template<size_t COUNT>
static int64_t write(const char (&buffer)[COUNT], size_t count = COUNT) noexcept
{
	return sys_write(STDOUT, buffer, count);
}

template<size_t COUNT>
static int64_t write(fd_t file_des, const char (&buffer)[COUNT], size_t count = COUNT) noexcept
{
	return sys_write(file_des, buffer, count);
}
