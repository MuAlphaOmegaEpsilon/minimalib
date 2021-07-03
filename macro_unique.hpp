#pragma once
#include "macro_concat.hpp"

/// Generate a unique identifier, starting from a base name, by appending the line number to the name provided.
#define UNIQUE(basename) CONCAT(basename, __LINE__)

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
