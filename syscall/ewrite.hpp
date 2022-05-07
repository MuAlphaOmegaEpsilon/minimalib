#pragma once
#include <errno.h>
#include <stdint.h>

// Error codes returned by write syscall
enum ewrite : int64_t
{
	DQUOT = -EDQUOT,			 // Disk quota exceeded
	DESTADDRREQ = -EDESTADDRREQ, // Destination address required
	PIPE = -EPIPE,				 // Broken pipe
	NOSPC = -ENOSPC,			 // No space left on device
	FBIG = -EFBIG,				 // File too large
	INVAL = -EINVAL,			 // Invalid argument
	FAULT = -EFAULT,			 // Bad address
	AGAIN = -EAGAIN,			 // No more processes
	WOULDBLOCK = -EWOULDBLOCK,	 // Operation would block
	BADF = -EBADF,				 // Bad file number
	IO = -EIO,					 // I/O error
	INTR = -EINTR,				 // Interrupted system call
	PERM = -EPERM,				 // Not super-user
};
