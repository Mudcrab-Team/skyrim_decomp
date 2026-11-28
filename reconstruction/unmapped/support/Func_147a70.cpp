// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x147a70 Func_147a70::HashKey
// Adapted bodies: none
#include "Func_147a70.h"

// Computes a multiplier-33 string hash modulo bucketCount.
std::uint32_t Func_147a70::HashKey(const char* key) const
{
    std::uint32_t hash = 0;
    while (*key)
    {
        hash = hash * 33u + static_cast<std::uint32_t>(static_cast<std::int32_t>(*key));
        ++key;
    }
    return hash % bucketCount;
}
