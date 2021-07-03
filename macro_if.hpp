#pragma once
// SPDX-License-Identifier: MIT

// Likely if shortcut
#define LIF(x) if (x) [[likely]]
// Unlikely if shortcut
#define UIF(x) if (x) [[unlikely]]
