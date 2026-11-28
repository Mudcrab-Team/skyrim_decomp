// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e2110 Unit1e2110::FindIndex1e2110
// Adapted bodies: none
#include "Unit1e2110.h"

// Searches the global pointer array and returns the index as a byte, or 0xFF if absent.
std::uint8_t Unit1e2110::FindIndex1e2110(const void* a_target)
{
    std::int32_t found = -1;
    for (std::uint32_t i = 0; i < g_entries1e2110.count && found == -1; ++i) {
        if (g_entries1e2110.data[i] == a_target) {
            found = static_cast<std::int32_t>(i);
        }
    }
    return found == -1 ? static_cast<std::uint8_t>(0xFF) : static_cast<std::uint8_t>(found);
}
