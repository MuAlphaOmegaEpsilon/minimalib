#pragma once
// SPDX-License-Identifier: MIT

#include "macro_concat.hpp"

/// Generate a unique identifier, starting from a base name, by appending the line number to the name provided.
#define UNIQUE(basename) CONCAT(basename, __LINE__)
