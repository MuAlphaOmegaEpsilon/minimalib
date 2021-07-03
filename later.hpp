#pragma once
#include "macro_unique.hpp"

template<class lambda_t>
struct later_t
{
	const lambda_t m_fn;
	constexpr later_t(lambda_t fn) noexcept : m_fn(fn) {}
	~later_t() noexcept { m_fn(); }
};
#define LATER(x) const later_t UNIQUE(later)([&](){x;})

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
