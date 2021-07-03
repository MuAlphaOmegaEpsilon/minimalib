#pragma once

// The second pass of the CONCAT macro, necessary to cover all the cases: do not use this.
#define _CONCAT(x, y) x##y
// Concatenate two strings together using the preprocessor.
#define CONCAT(x, y) _CONCAT(x, y)

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
