# Syscalls
A collection of POSIX-like functions to directly perform syscalls.

For platform-specific details like calling conventions and syscall numbering give a look at the corresponding markdown docs:
 - [Linux](README-linux.md)
 - [Windows](README-windows.md)
 - [MacOS](README-macos.md)

## write
Writes a given amount of bytes to a file referred by the corresponding file descriptor.<br>
Returns a positive integer to report the number of bytes written.<br>
Returns a negative integer to report error codes: use [`err.hpp`](../err.hpp) for a list of error values.

#### Overloads
##### int64_t write(const char (&buffer)[COUNT], size_t count = COUNT) [TEMPLATED]
```c++
write("Hello World!"); // Writes to stdout by default
```
##### int64_t write(fd_t file_des, const char (&buffer)[COUNT], size_t count = COUNT) [TEMPLATED]
```c++
write(myfile, "Hello World!");
```
##### int64_t write(const char* buffer, size_t count)
```c++
write("Hello World!", 12); // Writes to stdout by default
```
##### int64_t write(fd_t file_des, const char* buffer, size_t count)
```c++
write(myfile, "Hello World!", 12);
```

## Useful links
System calls for different architectures can be found here:
https://syscalls.w3challs.com/


