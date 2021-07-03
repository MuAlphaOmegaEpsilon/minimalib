#pragma once

static constexpr bool C_MINIMALIB_USE_SYSCALLS
{
#ifdef MINIMALIB_USE_SYSCALLS
	true
#else
	false
#endif
};

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
