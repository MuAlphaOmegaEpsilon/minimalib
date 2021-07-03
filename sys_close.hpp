#pragma once
#include "fd.hpp"

[[gnu::naked]] static int32_t sys_close(fd_t descriptor) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $3,%rax");
	asm("syscall");
	asm("retq");
// #elif __APPLE__ && __x86_64__
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented close function")
#endif
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
