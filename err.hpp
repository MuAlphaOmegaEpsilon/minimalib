#pragma once

#include <stdint.h>

#ifdef EPERM
	#error Header err.hpp cannot be used when errno.h is already included
#endif

constexpr int64_t EPERM = -1;	 // Operation not permitted
constexpr int64_t ENOENT = -2;	 // No such file or directory
constexpr int64_t ESRCH = -3;	 // No such process
constexpr int64_t EINTR = -4;	 // Interrupted system call
constexpr int64_t EIO = -5;		 // I/O error
constexpr int64_t ENXIO = -6;	 // No such device or address
constexpr int64_t E2BIG = -7;	 // Argument list too long
constexpr int64_t ENOEXEC = -8;	 // Exec format error
constexpr int64_t EBADF = -9;	 // Bad file number
constexpr int64_t ECHILD = -10;	 // No child processes
constexpr int64_t EAGAIN = -11;	 // Try again
constexpr int64_t ENOMEM = -12;	 // Out of memory
constexpr int64_t EACCES = -13;	 // Permission denied
constexpr int64_t EFAULT = -14;	 // Bad address
constexpr int64_t ENOTBLK = -15; // Block device required
constexpr int64_t EBUSY = -16;	 // Device or resource busy
constexpr int64_t EEXIST = -17;	 // File exists
constexpr int64_t EXDEV = -18;	 // Cross-device link
constexpr int64_t ENODEV = -19;	 // No such device
constexpr int64_t ENOTDIR = -20; // Not a directory
constexpr int64_t EISDIR = -21;	 // Is a directory
constexpr int64_t EINVAL = -22;	 // Invalid argument
constexpr int64_t ENFILE = -23;	 // File table overflow
constexpr int64_t EMFILE = -24;	 // Too many open files
constexpr int64_t ENOTTY = -25;	 // Not a typewriter
constexpr int64_t ETXTBSY = -26; // Text file busy
constexpr int64_t EFBIG = -27;	 // File too large
constexpr int64_t ENOSPC = -28;	 // No space left on device
constexpr int64_t ESPIPE = -29;	 // Illegal seek
constexpr int64_t EROFS = -30;	 // Read-only file system
constexpr int64_t EMLINK = -31;	 // Too many links
constexpr int64_t EPIPE = -32;	 // Broken pipe
constexpr int64_t EDOM = -33;	 // Math argument out of domain of func
constexpr int64_t ERANGE = -34;	 // Math result not representable
