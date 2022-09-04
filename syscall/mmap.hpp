#pragma once
#include "../fd.hpp"
#include "../offset.hpp"
#include <stddef.h>
#include <sys/mman.h>

[[gnu::naked]] static int64_t
_mmap(void* addr, size_t length, int prot, int flags, fd_t file, offset_t shift) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $9, %rax");
	asm("mov %rcx, %r10"); // Linux syscalls use R10 instead of RCX
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented mmap function")
#endif
}

[[maybe_unused]] static int64_t mmap(size_t length) noexcept
{
	return _mmap(
		nullptr, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd_t {0}, offset_t {0});
}

/*
[[maybe_unused, gnu::returns_nonnull]] static int64_t
mmap(fd_t file) noexcept
{
	#warning Length cannot be zero in mmap overload, this should be fixed to a sound value or the
interface changed altogether return mmap(nullptr, 0, PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_PRIVATE, file, 0);
}
*/
