#pragma once
#include "../fd.hpp"
#include <stddef.h>
#include <stdint.h>

enum WRITE_ERROR : int64_t
{
	EDQUOT = -132,		  // Disk quota exceeded
	EDESTADDRREQ = -121,  // Destination address required
	EPIPE = -32,		  // Broken pipe
	ENOSPC = -28,		  // No space left on device
	EFBIG = -27,		  // File too large
	EINVAL = -22,		  // Invalid argument
	EFAULT = -14,		  // Bad address
	EAGAIN = -11,		  // No more processes
	EWOULDBLOCK = EAGAIN, // Operation would block
	EBADF = -9,			  // Bad file number
	EIO = -5,			  // I/O error
	EINTR = -4,			  // Interrupted system call
	EPERM = -1,			  // Not super-user
};

[[gnu::naked]] static int64_t write([[maybe_unused]] fd file_des,
									[[maybe_unused]] const char* buffer,
									[[maybe_unused]] size_t count) noexcept
{
#ifdef __APPLE__
	asm("mov $0x2000004,%rax");
#elif __gnu_linux__
	asm("mov $1,%rax");
#endif
	asm("syscall");
	asm("retq");
}

[[maybe_unused]] static int64_t write(const char buffer[], size_t count)
{
	return write(STDOUT, buffer, count);
}

template<size_t COUNT>
int64_t write(const char (&buffer)[COUNT])
{
	return write(STDOUT, buffer, COUNT);
}

template<size_t COUNT>
int64_t write(fd file_des, const char (&buffer)[COUNT])
{
	return write(file_des, buffer, COUNT);
}
