#pragma once
// SPDX-License-Identifier: MIT

#include <stdint.h>

// The length of the string.
// Requires the string to be null terminated.
// The null termination is not counted in the result.
[[nodiscard]] constexpr static uint32_t len(const char* s) noexcept
{
	const char* needle = s;
	while(*needle) ++needle;
	return static_cast<uint32_t>(needle - s);
}
