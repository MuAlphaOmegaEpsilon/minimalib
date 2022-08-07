#pragma once
#include "../fd.hpp"
#include <sys/types.h>

[[gnu::naked]] static fd_t sys_open(const char* path, int flags, mode_t mode) noexcept
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
