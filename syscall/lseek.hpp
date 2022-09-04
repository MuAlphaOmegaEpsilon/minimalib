#pragma once
#include "../fd.hpp"
#include "../offset.hpp"

using stat_t = struct stat;

[[gnu::naked, maybe_unused]] static int32_t
lseek(fd_t file, offset_t shift, uint32_t whence) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $8, %rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented lseek function")
#endif
}
