// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x12b4840 Function12b4840
// Adapted bodies: none
#include "FreeFunction_12b4840.h"

// Searches the 200-entry lookup table for key and returns its associated value, or 2 if absent.
std::uint32_t Function12b4840(const void* key)
{
    std::uint32_t result = 2;
    for (std::size_t i = 0; i < 200; ++i) {
        if (key == g_table_12b4840[i].key) {
            result = g_table_12b4840[i].value;
            break;
        }
    }
    return result;
}
