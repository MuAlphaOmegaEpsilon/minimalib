#pragma once
#include "fd.hpp"

[[gnu::naked]] static int32_t close(fd_t descriptor) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $3,%rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented close function")
#endif
}
