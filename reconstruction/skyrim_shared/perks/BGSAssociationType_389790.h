// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSAssociationType, Function389790, unk00, names: GUESS(low); pairs of strings from offset 0x20
#pragma once

#include <cstdint>
#include <cstddef>

class BGSAssociationType
{
public:
    std::uint8_t unk00[0x20];
    const char* names[4][2];

    const char* Function389790(std::int32_t a_index, std::int32_t a_variant) const;  // compared: 0x389790
};
