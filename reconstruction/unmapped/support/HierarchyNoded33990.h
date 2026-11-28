// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// HierarchyNoded33990: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct HierarchyNoded33990
{
    std::uint16_t GetCachedValue();  // compared: 0xd33990

    std::uint64_t unk00[6];       // 0x00
    HierarchyNoded33990* parent;  // 0x30
    std::uint64_t unk38[22];      // 0x38
    std::uint32_t unkE8;          // 0xE8
    std::uint16_t unkEC;          // 0xEC
    std::uint16_t cachedValue;    // 0xEE
};
