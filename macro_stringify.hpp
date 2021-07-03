#pragma once
// SPDX-License-Identifier: MIT

// Stringify a given text by wrapping it with double quotes.
#define _STRINGIFY_INTERNAL(x) #x
#define STRINGIFY(x) _STRINGIFY_INTERNAL(x)
