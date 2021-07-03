#pragma once
#include <stddef.h>
#include <stdint.h>

using pollfd_t = struct pollfd;

[[gnu::naked, gnu::nonnull(1)]] static int32_t
poll(pollfd_t* files, uint32_t count, int64_t timeout_msecs) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $7, %rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented poll function")
#endif
}

template<size_t COUNT>
static int32_t poll(const char (&files)[COUNT]) noexcept
{
	return poll(files, COUNT, -1); // Negative timeout means infinite wait
}

template<size_t COUNT>
static int32_t poll(const char (&files)[COUNT], int64_t timeout_msecs) noexcept
{
	return poll(files, COUNT, timeout_msecs);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
