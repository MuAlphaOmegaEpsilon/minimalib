#pragma once
#include "fd.hpp"
#include "offset.hpp"
#include <stdint.h>
#include <stddef.h>
#include <sys/mman.h>

[[gnu::naked]]
static intptr_t mmap(void* addr, size_t length, int prot, int flags, fd_t file, offset_t off) noexcept
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

[[maybe_unused]]
static intptr_t mmap(size_t length) noexcept
{
	return mmap(nullptr,
				 length,
				 PROT_READ | PROT_WRITE | PROT_EXEC,
				 MAP_PRIVATE | MAP_ANONYMOUS,
				 fd_t {-1U},
				 offset_t {0});
}

[[maybe_unused]]
static intptr_t mmap(fd_t file, size_t length, offset_t off = offset_t {0}) noexcept
{
	return mmap(nullptr, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, file, off);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
