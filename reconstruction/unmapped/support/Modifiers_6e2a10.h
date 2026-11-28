// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Modifiers, Modifiers::GetAllZero: CRASHLOGGER_PDB(59818@2026.10.24)
// values: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Modifiers
{
    bool GetAllZero() const;  // compared: 0x6e2a10

    float values[3];  // 00
};
static_assert(sizeof(Modifiers) == 0x0C, "Modifiers size");
