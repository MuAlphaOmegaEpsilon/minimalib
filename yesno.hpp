#pragma once
#include "str.hpp"

constexpr static str_t yesno(bool v) { return str(v ? "yes" : "no"); }
constexpr static str_t YESNO(bool v) { return str(v ? "YES" : "NO"); }
constexpr static str_t YesNo(bool v) { return str(v ? "Yes" : "No"); }

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
