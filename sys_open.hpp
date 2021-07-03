#pragma once
#include "fd.hpp"
#include <fcntl.h>

[[gnu::naked, gnu::nonnull(1)]]
static fd_t open(const char* path, int32_t flags, mode_t mode) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $2, %rax");
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000005, %rax");
	asm("syscall");
	asm("retq");
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented open function")
#endif
}

[[maybe_unused, gnu::nonnull(1)]]
static fd_t open(const char* path) noexcept
{
	return open(path, O_RDWR, O_CREAT | O_APPEND);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
