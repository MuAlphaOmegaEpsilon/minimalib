#pragma once
#include <stdint.h>
#include <time.h>

/** Return the time in nanoseconds from the epoch (UTC), zero in case of
 * failure. */
[[nodiscard]]
static uint64_t nanos() noexcept
{
	timespec spec {};
	if(clock_gettime(CLOCK_REALTIME, &spec)) [[unlikely]]
		return 0; // Could not retrieve a valid time with the given clock
	return (static_cast<uint64_t>(spec.tv_sec) * 1000 * 1000 * 1000) + static_cast<uint64_t>(spec.tv_nsec);
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
