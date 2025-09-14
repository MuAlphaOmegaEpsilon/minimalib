#pragma once

#ifdef MINIMALIB_ENABLE_SYSCALLS
static constexpr bool C_ENABLE_SYSCALLS { true };
#else
static constexpr bool C_ENABLE_SYSCALLS { false };
#endif

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
