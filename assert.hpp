#pragma once
// SPDX-License-Identifier: MIT

#include "cat.hpp"
#include "macro_stringify.hpp"
#include <stdint.h>

#ifdef MINIMALIB_USE_SYSCALLS
#include "sys_write.hpp"
#include "sys_exit.hpp"
#else
#include <stdio.h>
#include <stdlib.h>
#endif

[[maybe_unused]]
static void assert(bool condition, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{
#ifndef NDEBUG
	if(condition) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is false, ", file, ':', fn_name, "():", line);
#ifdef MINIMALIB_USE_SYSCALLS
	sys_write(STDERR, emsg);
	sys_exit(1);
#else
	fwrite(emsg.view, 1, emsg.length, stderr);
	exit(1);
#endif
#endif
}

[[maybe_unused]]
static void assert(int64_t value, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{
#ifndef NDEBUG
	if(value) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is zero, ", file, ':', fn_name, "():", line);
#ifdef MINIMALIB_USE_SYSCALLS
	sys_write(STDERR, emsg);
	sys_exit(1);
#else
	fwrite(emsg.view, 1, emsg.length, stderr);
	exit(1);
#endif
#endif
}

[[maybe_unused]]
static void assert(uint64_t value, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{
#ifndef NDEBUG
	if(value) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is zero, ", file, ':', fn_name, "():", line);
#ifdef MINIMALIB_USE_SYSCALLS
	sys_write(STDERR, emsg);
	sys_exit(1);
#else
	fwrite(emsg.view, 1, emsg.length, stderr);
	exit(1);
#endif
#endif
}

[[maybe_unused]]
static void assert(void* ptr, const char* description, const char* file = __builtin_FILE(), const char* fn_name = __builtin_FUNCTION(), unsigned int line = __builtin_LINE())
{
#ifndef NDEBUG
	if(ptr) [[likely]] return;
	char ebuffer[1024];
	str_t emsg = cat(&ebuffer, "ASSERT: '", description, "' is nullptr, ", file, ':', fn_name, "():", line);
#ifdef MINIMALIB_USE_SYSCALLS
	sys_write(STDERR, emsg);
	sys_exit(1);
#else
	fwrite(emsg.view, 1, emsg.length, stderr);
	exit(1);
#endif
#endif
}

#define assert(x) assert(x, STRINGIFY(x))
