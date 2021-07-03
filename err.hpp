#pragma once
#include <errno.h>
#include <stdint.h>

constexpr int64_t C_EPERM   = -EPERM;   // Operation not permitted
constexpr int64_t C_ENOENT  = -ENOENT;  // No such file or directory
constexpr int64_t C_ESRCH   = -ESRCH;   // No such process
constexpr int64_t C_EINTR   = -EINTR;   // Interrupted system call
constexpr int64_t C_EIO     = -EIO;     // I/O error
constexpr int64_t C_ENXIO   = -ENXIO;   // No such device or address
constexpr int64_t C_E2BIG   = -E2BIG;   // Argument list too long
constexpr int64_t C_ENOEXEC = -ENOEXEC; // Exec format error
constexpr int64_t C_EBADF   = -EBADF;   // Bad file number
constexpr int64_t C_ECHILD  = -ECHILD;  // No child processes
constexpr int64_t C_EAGAIN  = -EAGAIN;  // Try again
constexpr int64_t C_ENOMEM  = -ENOMEM;  // Out of memory
constexpr int64_t C_EACCES  = -EACCES;  // Permission denied
constexpr int64_t C_EFAULT  = -EFAULT;  // Bad address
constexpr int64_t C_ENOTBLK = -ENOTBLK; // Block device required
constexpr int64_t C_EBUSY   = -EBUSY;   // Device or resource busy
constexpr int64_t C_EEXIST  = -EEXIST;  // File exists
constexpr int64_t C_EXDEV   = -EXDEV;   // Tried to move file to different device
constexpr int64_t C_ENODEV  = -ENODEV;  // No such device
constexpr int64_t C_ENOTDIR = -ENOTDIR; // Not a directory
constexpr int64_t C_EISDIR  = -EISDIR;  // Is a directory
constexpr int64_t C_EINVAL  = -EINVAL;  // Invalid argument
constexpr int64_t C_ENFILE  = -ENFILE;  // File table overflow
constexpr int64_t C_EMFILE  = -EMFILE;  // Too many open files
constexpr int64_t C_ENOTTY  = -ENOTTY;  // Not a typewriter
constexpr int64_t C_ETXTBSY = -ETXTBSY; // Text file busy
constexpr int64_t C_EFBIG   = -EFBIG;   // File too large
constexpr int64_t C_ENOSPC  = -ENOSPC;  // No space left on device
constexpr int64_t C_ESPIPE  = -ESPIPE;  // Illegal seek
constexpr int64_t C_EROFS   = -EROFS;   // Read-only file system
constexpr int64_t C_EMLINK  = -EMLINK;  // Too many links
constexpr int64_t C_EPIPE   = -EPIPE;   // Broken pipe
constexpr int64_t C_EDOM    = -EDOM;    // Math argument out of domain of func
constexpr int64_t C_ERANGE  = -ERANGE;  // Math result not representable

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
