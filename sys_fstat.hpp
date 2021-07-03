#pragma once
#include "fd.hpp"

using stat_t = struct stat;

[[gnu::naked, gnu::nonnull(2)]] static int32_t fstat(fd_t file, stat_t* info) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $5, %rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented fstat function")
#endif
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
