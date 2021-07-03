#pragma once
#include "len.hpp"
#include "macro_count.hpp"
#include <stdint.h>

template<unsigned int COUNT>
consteval static uint32_t lenfmt(const char(&)[COUNT]) noexcept { return  COUNT - 1; }
consteval static uint32_t lenfmt(              auto s) noexcept { return s.C_LENFMT; }
consteval static uint32_t lenfmt(       const char* s) noexcept { return     len(s); }
consteval static uint32_t lenfmt(            uint64_t) noexcept { return         20; } // From 00000000000000000000 to 18446744073709551615
consteval static uint32_t lenfmt(             int64_t) noexcept { return         20; } // From -9223372036854775808 to  9223372036854775807
consteval static uint32_t lenfmt(            uint32_t) noexcept { return         10; } // From  0000000000 to  4294967295
consteval static uint32_t lenfmt(             int32_t) noexcept { return         11; } // From -2147483648 to +2147483647
consteval static uint32_t lenfmt(            uint16_t) noexcept { return          5; } // From  00000 to  65535
consteval static uint32_t lenfmt(             int16_t) noexcept { return          6; } // From -32768 to +32767
consteval static uint32_t lenfmt(             uint8_t) noexcept { return          3; } // From 000 to 255
consteval static uint32_t lenfmt(              int8_t) noexcept { return          4; } // From -128 to +127
consteval static uint32_t lenfmt(                char) noexcept { return          1; }
consteval static uint32_t lenfmt(                    ) noexcept { return          0; }

// If you're thinking "WTF is this MACRO crap!? Just use a variadic template!" then I am with you.
//
// template<class... args>
// consteval static uint32_t lenfmt(args... pack) noexcept { return (lenfmt(pack) + ...); }
//
// I TRIED to use the above variadic template function, but that decays stack allocated
// C-style arrays (e.g. char[N]) into the corresponding pointer (e.g. char*), therefore losing all
// information about array length and breaking the compile time constraint on the lenfmt calculation.
#define LENFMT63(v, ...) lenfmt(v) + LENFMT62(__VA_ARGS__)
#define LENFMT62(v, ...) lenfmt(v) + LENFMT61(__VA_ARGS__)
#define LENFMT61(v, ...) lenfmt(v) + LENFMT60(__VA_ARGS__)
#define LENFMT60(v, ...) lenfmt(v) + LENFMT59(__VA_ARGS__)
#define LENFMT59(v, ...) lenfmt(v) + LENFMT58(__VA_ARGS__)
#define LENFMT58(v, ...) lenfmt(v) + LENFMT57(__VA_ARGS__)
#define LENFMT57(v, ...) lenfmt(v) + LENFMT56(__VA_ARGS__)
#define LENFMT56(v, ...) lenfmt(v) + LENFMT55(__VA_ARGS__)
#define LENFMT55(v, ...) lenfmt(v) + LENFMT54(__VA_ARGS__)
#define LENFMT54(v, ...) lenfmt(v) + LENFMT53(__VA_ARGS__)
#define LENFMT53(v, ...) lenfmt(v) + LENFMT52(__VA_ARGS__)
#define LENFMT52(v, ...) lenfmt(v) + LENFMT51(__VA_ARGS__)
#define LENFMT51(v, ...) lenfmt(v) + LENFMT50(__VA_ARGS__)
#define LENFMT50(v, ...) lenfmt(v) + LENFMT49(__VA_ARGS__)
#define LENFMT49(v, ...) lenfmt(v) + LENFMT48(__VA_ARGS__)
#define LENFMT48(v, ...) lenfmt(v) + LENFMT47(__VA_ARGS__)
#define LENFMT47(v, ...) lenfmt(v) + LENFMT46(__VA_ARGS__)
#define LENFMT46(v, ...) lenfmt(v) + LENFMT45(__VA_ARGS__)
#define LENFMT45(v, ...) lenfmt(v) + LENFMT44(__VA_ARGS__)
#define LENFMT44(v, ...) lenfmt(v) + LENFMT43(__VA_ARGS__)
#define LENFMT43(v, ...) lenfmt(v) + LENFMT42(__VA_ARGS__)
#define LENFMT42(v, ...) lenfmt(v) + LENFMT41(__VA_ARGS__)
#define LENFMT41(v, ...) lenfmt(v) + LENFMT40(__VA_ARGS__)
#define LENFMT40(v, ...) lenfmt(v) + LENFMT39(__VA_ARGS__)
#define LENFMT39(v, ...) lenfmt(v) + LENFMT38(__VA_ARGS__)
#define LENFMT38(v, ...) lenfmt(v) + LENFMT37(__VA_ARGS__)
#define LENFMT37(v, ...) lenfmt(v) + LENFMT36(__VA_ARGS__)
#define LENFMT36(v, ...) lenfmt(v) + LENFMT35(__VA_ARGS__)
#define LENFMT35(v, ...) lenfmt(v) + LENFMT34(__VA_ARGS__)
#define LENFMT34(v, ...) lenfmt(v) + LENFMT33(__VA_ARGS__)
#define LENFMT33(v, ...) lenfmt(v) + LENFMT32(__VA_ARGS__)
#define LENFMT32(v, ...) lenfmt(v) + LENFMT31(__VA_ARGS__)
#define LENFMT31(v, ...) lenfmt(v) + LENFMT30(__VA_ARGS__)
#define LENFMT30(v, ...) lenfmt(v) + LENFMT29(__VA_ARGS__)
#define LENFMT29(v, ...) lenfmt(v) + LENFMT28(__VA_ARGS__)
#define LENFMT28(v, ...) lenfmt(v) + LENFMT27(__VA_ARGS__)
#define LENFMT27(v, ...) lenfmt(v) + LENFMT26(__VA_ARGS__)
#define LENFMT26(v, ...) lenfmt(v) + LENFMT25(__VA_ARGS__)
#define LENFMT25(v, ...) lenfmt(v) + LENFMT24(__VA_ARGS__)
#define LENFMT24(v, ...) lenfmt(v) + LENFMT23(__VA_ARGS__)
#define LENFMT23(v, ...) lenfmt(v) + LENFMT22(__VA_ARGS__)
#define LENFMT22(v, ...) lenfmt(v) + LENFMT21(__VA_ARGS__)
#define LENFMT21(v, ...) lenfmt(v) + LENFMT20(__VA_ARGS__)
#define LENFMT20(v, ...) lenfmt(v) + LENFMT19(__VA_ARGS__)
#define LENFMT19(v, ...) lenfmt(v) + LENFMT18(__VA_ARGS__)
#define LENFMT18(v, ...) lenfmt(v) + LENFMT17(__VA_ARGS__)
#define LENFMT17(v, ...) lenfmt(v) + LENFMT16(__VA_ARGS__)
#define LENFMT16(v, ...) lenfmt(v) + LENFMT15(__VA_ARGS__)
#define LENFMT15(v, ...) lenfmt(v) + LENFMT14(__VA_ARGS__)
#define LENFMT14(v, ...) lenfmt(v) + LENFMT13(__VA_ARGS__)
#define LENFMT13(v, ...) lenfmt(v) + LENFMT12(__VA_ARGS__)
#define LENFMT12(v, ...) lenfmt(v) + LENFMT11(__VA_ARGS__)
#define LENFMT11(v, ...) lenfmt(v) + LENFMT10(__VA_ARGS__)
#define LENFMT10(v, ...) lenfmt(v) + LENFMT9(__VA_ARGS__)
#define LENFMT9(v,  ...) lenfmt(v) + LENFMT8(__VA_ARGS__)
#define LENFMT8(v,  ...) lenfmt(v) + LENFMT7(__VA_ARGS__)
#define LENFMT7(v,  ...) lenfmt(v) + LENFMT6(__VA_ARGS__)
#define LENFMT6(v,  ...) lenfmt(v) + LENFMT5(__VA_ARGS__)
#define LENFMT5(v,  ...) lenfmt(v) + LENFMT4(__VA_ARGS__)
#define LENFMT4(v,  ...) lenfmt(v) + LENFMT3(__VA_ARGS__)
#define LENFMT3(v,  ...) lenfmt(v) + LENFMT2(__VA_ARGS__)
#define LENFMT2(v,  ...) lenfmt(v) + LENFMT1(__VA_ARGS__)
#define LENFMT1(v)       lenfmt(v)
#define LENFMT0()               0
#define _LENFMT_INTERNAL_2(IDX, ...) LENFMT ## IDX(__VA_ARGS__)
#define _LENFMT_INTERNAL_1(IDX, ...) _LENFMT_INTERNAL_2(IDX, __VA_ARGS__)
#define LENFMT(...) _LENFMT_INTERNAL_1(M_COUNT(__VA_ARGS__), __VA_ARGS__)

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
