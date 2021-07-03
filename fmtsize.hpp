#pragma once
#include "len.hpp"

constexpr static uint32_t _fmtsize(  auto s) noexcept { return len(s); }
constexpr static uint32_t _fmtsize(    char) noexcept { return      1; }
constexpr static uint32_t _fmtsize(  int8_t) noexcept { return      4; } // From -128 to 127
constexpr static uint32_t _fmtsize( uint8_t) noexcept { return      3; } // From 0 to 255
constexpr static uint32_t _fmtsize( int16_t) noexcept { return      6; } // From -32768 to 32767
constexpr static uint32_t _fmtsize(uint16_t) noexcept { return      5; } // From 0 to 65535
constexpr static uint32_t _fmtsize( int32_t) noexcept { return     11; } // From -2147483648 to 2147483647
constexpr static uint32_t _fmtsize(uint32_t) noexcept { return     10; } // From 0 to 4294967295
constexpr static uint32_t _fmtsize( int64_t) noexcept { return     20; } // From -9223372036854775808 to 9223372036854775807
constexpr static uint32_t _fmtsize(uint64_t) noexcept { return     20; } // From 0 to 18446744073709551615

template<class... args>
constexpr static uint32_t fmtsize(args... pack) noexcept { return (_fmtsize(pack) + ...); }

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
