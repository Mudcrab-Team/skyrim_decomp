// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Func_147a70: GUESS(low)
#pragma once

#include <cstdint>

struct Func_147a70
{
    std::uint32_t HashKey(const char* key) const;

    std::uint64_t unk00;
    std::uint32_t bucketCount;
};
