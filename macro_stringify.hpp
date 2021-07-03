#pragma once

// Stringify a given text by wrapping it with double quotes.
#define _STRINGIFY_INTERNAL(x) #x
#define STRINGIFY(x) _STRINGIFY_INTERNAL(x)

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
