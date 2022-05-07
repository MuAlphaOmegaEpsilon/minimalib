#pragma once
// File descriptor
//
// Contains the identifier of an open file.
struct fd_t
{
	unsigned int id;
};
static constexpr fd_t STDIN {0};
static constexpr fd_t STDOUT {1};
static constexpr fd_t STDERR {2};
