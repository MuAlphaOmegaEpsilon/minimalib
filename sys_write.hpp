#pragma once
#include "stdstreams.hpp"
#include "str.hpp"
#include <stddef.h>
#include <stdint.h>

[[gnu::naked, gnu::nonnull(2)]] static int64_t
sys_write(fd_t file_des, const char* buffer, size_t count) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $1, %rax");
	asm("syscall");
	asm("retq");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000004, %rax");
	asm("syscall");
	// On MacOS the errno value is not returned in %rax as a negative value (as in Linux), but a
	// positive value is returned and the CARRY flag is set to indicate that an error occurred. To
	// keep the behaviour consistent with Linux the value in %rax needs to be negated if the CARRY
	// flag is set. This can be done in a few ways, the easiest being a jump that branches the flow
	// in two different paths of execution. Using a jump might be expensive for the branch-predictor
	// if it fails to predict the right flow. The other way to achieve this is to move the CARRY
	// flag in a register and compute the right value in %rax only using branchless math operations.
	// It's hard to tell beforehand which method is the most performant, therefore for the moment
	// the easiest implementation is the one used, and the serial flow gives priority to the
	// errorless branch.
	asm("jc write_negate_errno");
	asm("retq");
	asm("write_negate_errno:");
	asm("negq %rax");
	asm("retq");
#elif _WIN32 && __x86_64__
	asm("call WriteFile");
#else
	#pragma message("Unimplemented write function")
#endif
}

static int64_t sys_write(fd_t fd, char c) noexcept
{
	return sys_write(fd, &c, 1);
}

template <uint32_t N>
static int64_t sys_write(fd_t fd, const char(&s)[N]) noexcept
{
	return sys_write(fd, s, N-1);
}

static int64_t sys_write(fd_t fd, str_t s) noexcept
{
	return sys_write(fd, s.view, s.length);
}

static int64_t sys_write(char c) noexcept
{
	return sys_write(STDOUT, &c, 1);
}

template <uint32_t N>
static int64_t sys_write(const char(&s)[N]) noexcept
{
	return sys_write(STDOUT, s, N-1);
}

static int64_t sys_write(str_t s) noexcept
{
	return sys_write(STDOUT, s.view, s.length);
}

[[gnu::nonnull(1)]] static int64_t sys_write(const char* buffer, size_t count) noexcept
{
	return sys_write(STDOUT, buffer, count);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
