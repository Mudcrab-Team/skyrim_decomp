// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiColor, NiColor::Clamp: CRASHLOGGER_PDB(59818@2026.10.24)
// r, g, b: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiColor
{
    void Clamp();  // compared: 0xef2e80

    float r;  // 00
    float g;  // 04
    float b;  // 08
};
static_assert(sizeof(NiColor) == 0x0C, "NiColor size");
