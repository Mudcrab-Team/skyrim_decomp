// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1e2d80 Function1e2d80
// Adapted bodies: none
#include <cstring>
#include "FreeFunction_1e2d80.h"

// Lazily zeroes a 138-entry pointer table and returns the entry for a_index or null if out of range.
void* Function1e2d80(std::uint8_t a_index)
{
    if (!gTableInitialized1e2d80) {
        std::memset(gTable1e2d80, 0, sizeof(gTable1e2d80));
        gTableInitialized1e2d80 = true;
    }
    if (a_index < 138) {
        return gTable1e2d80[a_index];
    }
    return nullptr;
}
