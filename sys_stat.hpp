#pragma once

using stat_t = struct stat;

[[gnu::naked, gnu::nonnull(1, 2)]] static int stat(const char* path, stat_t* info) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $4, %rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented stat function")
#endif
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
