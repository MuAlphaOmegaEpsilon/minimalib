#pragma once
// File descriptor
//
// Contains the identifier of an open file.
struct fd_t
{
	unsigned int id;
};

#if _WIN32
extern const fd_t STDIN;
extern const fd_t STDOUT;
extern const fd_t STDERR;
#else
static constexpr fd_t STDIN {0};
static constexpr fd_t STDOUT {1};
static constexpr fd_t STDERR {2};
#endif
