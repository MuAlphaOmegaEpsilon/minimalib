#pragma once

#ifdef NDEBUG
static constexpr bool C_DEBUG { false };
static constexpr bool C_RELEASE { true };
#else
static constexpr bool C_DEBUG { true };
static constexpr bool C_RELEASE { false };
#endif

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
