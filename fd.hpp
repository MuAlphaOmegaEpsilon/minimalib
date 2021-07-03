#pragma once
// SPDX-License-Identifier: MIT

#include <stdint.h>

// File descriptor, contains the identifier of an open file.
struct fd_t
{
	uint32_t id;
};
