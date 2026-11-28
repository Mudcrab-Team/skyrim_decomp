// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BipedSlot21ac70, BipedAnim21ac70, CountActiveSlots, item, slots, unk00, unk08: GUESS(low)
#pragma once

#include <cstdint>

struct BipedSlot21ac70
{
    void* item;               // 00
    std::uint8_t unk08[0x70]; // 08
};

static_assert(sizeof(BipedSlot21ac70) == 0x78, "BipedSlot21ac70 size");

class BipedAnim21ac70
{
public:
    std::uint8_t CountActiveSlots() const;

    std::uint8_t unk00[0xF30];   // 000
    BipedSlot21ac70 slots[8];    // F30
};
