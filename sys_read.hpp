#pragma once
#include "fd.hpp"
#include "stdstreams.hpp"
#include <stddef.h>
#include <stdint.h>

[[gnu::naked, gnu::nonnull(2)]] static int64_t read(fd_t descriptor,
													const char* buffer,
													size_t count) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("xor %rax,%rax"); // The syscall ID for read is 0, so RAX is zeroed out
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000003,%rax");
	asm("syscall");
	asm("retq");
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented write function")
#endif
}

[[maybe_unused, gnu::nonnull(1)]] static int64_t read(const char buffer[], size_t count)
{
	return read(STDIN, buffer, count);
}

template<size_t N>
int64_t read(const char (&buffer)[N])
{
	return read(STDIN, buffer, N);
}

template<size_t N>
int64_t read(fd_t descriptor, const char (&buffer)[N])
{
	return read(descriptor, buffer, N);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
