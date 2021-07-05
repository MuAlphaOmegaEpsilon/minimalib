#pragma once
/// \file
/// \brief Macro to stringify a token.

/// Second step of the STR macro: do not use this.
#define _STR_IMPL(x) #x
/// Stringify the passed parameter.
#define STR(x) _STR_IMPL((x))
