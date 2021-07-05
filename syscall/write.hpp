#pragma once
#include "fd.hpp"
#include <stddef.h>

[[gnu::naked]] static int write([[maybe_unused]] fd file_des,
						 [[maybe_unused]] const char* buffer,
						 [[maybe_unused]] size_t count) noexcept
{
	asm("mov $1,%rax");
	asm("syscall");
	asm("retq");
}

template<size_t COUNT>
int write(const char (&buffer)[COUNT])
{
	return write(STDOUT, buffer, COUNT);
}

template<size_t COUNT>
int write(fd file_des, const char (&buffer)[COUNT])
{
	return write(file_des, buffer, COUNT);
}
