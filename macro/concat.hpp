#pragma once
/// \file
/// \brief Macro to concatenate tokens.

/// The second step of the CONCAT macro: do not use this.
#define _CONCAT_IMPL(x, y) x##y
/// A macro to concatenate two strings together.
#define CONCAT(x, y) _CONCAT_IMPL(x, y)
