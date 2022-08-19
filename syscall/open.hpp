#pragma once
#include "../fd.hpp"
#include <fcntl.h>

[[gnu::naked, gnu::nonnull(1)]] static fd_t open(const char* path, int flags, mode_t mode) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $2, %rax");
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000005, %rax");
	asm("syscall");
	asm("retq");
#else
	#pragma message("Unimplemented write function")
#endif
}

[[maybe_unused, gnu::nonnull(1)]] static fd_t open(const char* path) noexcept
{
	return open(path, O_RDWR, O_CREAT | O_APPEND);
}
