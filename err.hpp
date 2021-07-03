#pragma once
// SPDX-License-Identifier: MIT

#include <errno.h>
#include <stdint.h>

constexpr int64_t E_PERM   = -EPERM;   // Operation not permitted
constexpr int64_t E_NOENT  = -ENOENT;  // No such file or directory
constexpr int64_t E_SRCH   = -ESRCH;   // No such process
constexpr int64_t E_INTR   = -EINTR;   // Interrupted system call
constexpr int64_t E_IO     = -EIO;     // I/O error
constexpr int64_t E_NXIO   = -ENXIO;   // No such device or address
constexpr int64_t E_2BIG   = -E2BIG;   // Argument list too long
constexpr int64_t E_NOEXEC = -ENOEXEC; // Exec format error
constexpr int64_t E_BADF   = -EBADF;   // Bad file number
constexpr int64_t E_CHILD  = -ECHILD;  // No child processes
constexpr int64_t E_AGAIN  = -EAGAIN;  // Try again
constexpr int64_t E_NOMEM  = -ENOMEM;  // Out of memory
constexpr int64_t E_ACCES  = -EACCES;  // Permission denied
constexpr int64_t E_FAULT  = -EFAULT;  // Bad address
constexpr int64_t E_NOTBLK = -ENOTBLK; // Block device required
constexpr int64_t E_BUSY   = -EBUSY;   // Device or resource busy
constexpr int64_t E_EXIST  = -EEXIST;  // File exists
constexpr int64_t E_XDEV   = -EXDEV;   // Tried to move file to different device
constexpr int64_t E_NODEV  = -ENODEV;  // No such device
constexpr int64_t E_NOTDIR = -ENOTDIR; // Not a directory
constexpr int64_t E_ISDIR  = -EISDIR;  // Is a directory
constexpr int64_t E_INVAL  = -EINVAL;  // Invalid argument
constexpr int64_t E_NFILE  = -ENFILE;  // File table overflow
constexpr int64_t E_MFILE  = -EMFILE;  // Too many open files
constexpr int64_t E_NOTTY  = -ENOTTY;  // Not a typewriter
constexpr int64_t E_TXTBSY = -ETXTBSY; // Text file busy
constexpr int64_t E_FBIG   = -EFBIG;   // File too large
constexpr int64_t E_NOSPC  = -ENOSPC;  // No space left on device
constexpr int64_t E_SPIPE  = -ESPIPE;  // Illegal seek
constexpr int64_t E_ROFS   = -EROFS;   // Read-only file system
constexpr int64_t E_MLINK  = -EMLINK;  // Too many links
constexpr int64_t E_PIPE   = -EPIPE;   // Broken pipe
constexpr int64_t E_DOM    = -EDOM;    // Math argument out of domain of func
constexpr int64_t E_RANGE  = -ERANGE;  // Math result not representable
