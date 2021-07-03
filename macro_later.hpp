#pragma once
// SPDX-License-Identifier: MIT

#include "scope_guard.hpp"
#include "macro_unique.hpp"

// Execute the given lambda when exiting the scope.
#define LATER thin::scope_guard UNIQUE(scopeGuard) =
