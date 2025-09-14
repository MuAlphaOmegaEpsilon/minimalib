#pragma once
#include "cat.hpp"
#include "enable_syscalls.hpp"
#include "ndebug.hpp"
#include "sys_exit.hpp"
#include "sys_write.hpp"
#include <stdint.h>

// Forward declare FILE, stderr, fwrite and exit to avoid including stdio.h and stdlib.h
class FILE;
extern FILE* stderr;
extern size_t fwrite (const void *, size_t, size_t, FILE *);
extern "C" [[noreturn]] void exit(int) noexcept;

[[maybe_unused]]
static void assert(bool condition, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{	if constexpr(C_RELEASE)
		return;
	if(condition) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is false, ", file, ':', fn_name, "():", line);
	C_ENABLE_SYSCALLS ? sys_write(STDERR, emsg) : fwrite(emsg.view, 1, emsg.length, stderr);
	C_ENABLE_SYSCALLS ? sys_exit(1)             : exit(1);
}
[[maybe_unused]]
static void assert(int64_t value, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{	if constexpr(C_RELEASE)
		return;
	if(value) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is zero, ", file, ':', fn_name, "():", line);
	C_ENABLE_SYSCALLS ? sys_write(STDERR, emsg) : fwrite(emsg.view, 1, emsg.length, stderr);
	C_ENABLE_SYSCALLS ? sys_exit(1)             : exit(1);
}
[[maybe_unused]]
static void assert(uint64_t value, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{	if constexpr(C_RELEASE)
		return;
	if(value) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is zero, ", file, ':', fn_name, "():", line);
	C_ENABLE_SYSCALLS ? sys_write(STDERR, emsg) : fwrite(emsg.view, 1, emsg.length, stderr);
	C_ENABLE_SYSCALLS ? sys_exit(1)             : exit(1);
}
[[maybe_unused]]
static void assert(void* ptr, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{	if constexpr(C_RELEASE)
		return;
	if(ptr) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is nullptr, ", file, ':', fn_name, "():", line);
	C_ENABLE_SYSCALLS ? sys_write(STDERR, emsg) : fwrite(emsg.view, 1, emsg.length, stderr);
	C_ENABLE_SYSCALLS ? sys_exit(1)             : exit(1);
}

#include "macro_pretty_function.hpp" // IWYU pragma: keep
#include "macro_stringify.hpp"
#define assert(x) assert(x, STRINGIFY(x), __FILE__, __PRETTY_FUNCTION__, __LINE__)

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
