#pragma once

static constexpr bool C_DEBUG
{
#ifdef NDEBUG
	false
#else
	true
#endif
};

static constexpr bool C_RELEASE
{
#ifdef NDEBUG
	true
#else
	false
#endif
};

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
