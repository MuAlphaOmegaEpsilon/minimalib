#pragma once
#include "str.hpp"

// Text colors
#define M_BLACK              "\033[30m"
#define M_RED                "\033[31m"
#define M_GREEN              "\033[32m"
#define M_YELLOW             "\033[33m"
#define M_BLUE               "\033[34m"
#define M_MAGENTA            "\033[35m"
#define M_CYAN               "\033[36m"
#define M_WHITE              "\033[37m"
// Bright text colors
#define M_BLACK_BRIGHT       "\033[30;1m"
#define M_RED_BRIGHT         "\033[31;1m"
#define M_GREEN_BRIGHT       "\033[32;1m"
#define M_YELLOW_BRIGHT      "\033[33;1m"
#define M_BLUE_BRIGHT        "\033[34;1m"
#define M_MAGENTA_BRIGHT     "\033[35;1m"
#define M_CYAN_BRIGHT        "\033[36;1m"
#define M_WHITE_BRIGHT       "\033[37;1m"
// Background colors
#define M_BLACK_BACKGROUND   "\033[40m"
#define M_RED_BACKGROUND     "\033[41m"
#define M_GREEN_BACKGROUND   "\033[42m"
#define M_YELLOW_BACKGROUND  "\033[43m"
#define M_BLUE_BACKGROUND    "\033[44m"
#define M_MAGENTA_BACKGROUND "\033[45m"
#define M_CYAN_BACKGROUND    "\033[46m"
#define M_WHITE_BACKGROUND   "\033[47m"
// Reset
#define M_NC                 "\033[0m"  // No color, use this to reset previous color changes

// Text colors
constexpr static str_t C_BLACK              = str(M_BLACK             ); // Set the text color to black
constexpr static str_t C_RED                = str(M_RED               ); // Set the text color to red
constexpr static str_t C_GREEN              = str(M_GREEN             ); // Set the text color to green
constexpr static str_t C_YELLOW             = str(M_YELLOW            ); // Set the text color to yellow
constexpr static str_t C_BLUE               = str(M_BLUE              ); // Set the text color to blue
constexpr static str_t C_MAGENTA            = str(M_MAGENTA           ); // Set the text color to magenta
constexpr static str_t C_CYAN               = str(M_CYAN              ); // Set the text color to cyan
constexpr static str_t C_WHITE              = str(M_WHITE             ); // Set the text color to white
// Bright text colors
constexpr static str_t C_BLACK_BRIGHT       = str(M_BLACK_BRIGHT      ); // Set the text color to bright black
constexpr static str_t C_RED_BRIGHT         = str(M_RED_BRIGHT        ); // Set the text color to bright red
constexpr static str_t C_GREEN_BRIGHT       = str(M_GREEN_BRIGHT      ); // Set the text color to bright green
constexpr static str_t C_YELLOW_BRIGHT      = str(M_YELLOW_BRIGHT     ); // Set the text color to bright yellow
constexpr static str_t C_BLUE_BRIGHT        = str(M_BLUE_BRIGHT       ); // Set the text color to bright blue
constexpr static str_t C_MAGENTA_BRIGHT     = str(M_MAGENTA_BRIGHT    ); // Set the text color to bright magenta
constexpr static str_t C_CYAN_BRIGHT        = str(M_CYAN_BRIGHT       ); // Set the text color to bright cyan
constexpr static str_t C_WHITE_BRIGHT       = str(M_WHITE_BRIGHT      ); // Set the text color to bright white
// Background colors
constexpr static str_t C_BLACK_BACKGROUND   = str(M_BLACK_BACKGROUND  ); // Set the text background color to black
constexpr static str_t C_RED_BACKGROUND     = str(M_RED_BACKGROUND    ); // Set the text background color to red
constexpr static str_t C_GREEN_BACKGROUND   = str(M_GREEN_BACKGROUND  ); // Set the text background color to green
constexpr static str_t C_YELLOW_BACKGROUND  = str(M_YELLOW_BACKGROUND ); // Set the text background color to yellow
constexpr static str_t C_BLUE_BACKGROUND    = str(M_BLUE_BACKGROUND   ); // Set the text background color to blue
constexpr static str_t C_MAGENTA_BACKGROUND = str(M_MAGENTA_BACKGROUND); // Set the text background color to magenta
constexpr static str_t C_CYAN_BACKGROUND    = str(M_CYAN_BACKGROUND   ); // Set the text background color to cyan
constexpr static str_t C_WHITE_BACKGROUND   = str(M_WHITE_BACKGROUND  ); // Set the text background color to white
// Reset
constexpr static str_t C_NC                 = str(M_NC                ); // No color, use this to reset previous changes

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
