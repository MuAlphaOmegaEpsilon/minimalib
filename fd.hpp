#pragma once
#include <stdint.h>

// File descriptor, contains the identifier of an open file.
struct fd_t
{
	uint32_t id;
};

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
