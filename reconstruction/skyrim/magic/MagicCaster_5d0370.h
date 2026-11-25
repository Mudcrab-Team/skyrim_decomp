// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MagicCaster, MagicCaster::ResetEntries, MagicCasterEntry, MagicCasterEntry fields: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct MagicCasterEntry
{
    int32_t id;
    uint8_t flag;
    int32_t value;
};

class MagicCaster
{
public:
    MagicCasterEntry* entries;

    void ResetEntries(uint32_t a_first, uint32_t a_count);  // compared: 0x5d0370
};
