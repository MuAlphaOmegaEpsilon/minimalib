#pragma once
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

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
