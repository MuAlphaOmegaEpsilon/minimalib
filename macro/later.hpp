#pragma once
/// \file
/// \brief Macro that simplifies the usage of scope_guards.

#include "../thin/scope_guard.hpp"
#include "unique.hpp"
/// The execution of the given lambda will be performed when exiting the scope.
#define LATER thin::scope_guard UNIQUE(scopeGuard) =
