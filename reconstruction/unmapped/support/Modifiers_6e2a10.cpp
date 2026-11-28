// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0x6e2a10 Modifiers::GetAllZero
#include "Modifiers_6e2a10.h"

// Return true if all three modifier values are zero.
bool Modifiers::GetAllZero() const
{
    bool allZero = true;
    for (std::uint32_t i = 0; i < 3 && allZero; ++i) {
        allZero = (values[i] == 0.0f);
    }
    return allZero;
}
