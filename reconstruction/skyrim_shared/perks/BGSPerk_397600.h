// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSPerk, BGSPerk::CompareOrder: GUESS(low)
// primaryKey, secondaryKey, pad00: GUESS(low); byte members at 0x9 and 0x8, roles unknown
#pragma once

#include <cstdint>

class BGSPerk
{
public:
    int CompareOrder(const BGSPerk& a_other);  // compared: 0x397600

    std::uint8_t pad00[0x8];
    std::uint8_t secondaryKey;
    std::uint8_t primaryKey;
};
