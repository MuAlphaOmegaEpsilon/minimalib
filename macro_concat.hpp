#pragma once
// SPDX-License-Identifier: MIT

// The second step of the CONCAT macro: do not use this.
#define _CONCAT_IMPL(x, y) x##y
// Concatenate two strings together using the preprocessor.
#define CONCAT(x, y) _CONCAT_IMPL(x, y)
