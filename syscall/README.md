# Syscalls
Here is a collection of POSIX-like functions to directly perform syscalls.

## write
Write a given amount of bytes to a file referred by the corresponding file descriptor.

### Overloads
#### int64_t write(fd_t file_des, const char* buffer, size_t count)
#### int64_t write(const char* buffer, size_t count) noexcept
#### int64_t write(const char (&buffer)[COUNT], size_t count = COUNT) [TEMPLATED]
#### int64_t write(fd_t file_des, const char (&buffer)[COUNT], size_t count = COUNT) [TEMPLATED]


## Useful links
System calls for different architectures can be found here:
https://syscalls.w3challs.com/


