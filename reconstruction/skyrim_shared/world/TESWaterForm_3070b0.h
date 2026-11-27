// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterForm::Function3070b0: GUESS(low); the name comes from the inventory
// TESWaterForm, WaterEntry, WaterEntry::Function_eb1380, entry80, entry90, entryA0, entryB0: STANDIN GUESS(low); four 0x10-byte members at 0x80 and the callee at 0xeb1380, read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class WaterEntry
{
public:
    void* Function_eb1380();  // callee at 0xeb1380, not compared here
    std::uint8_t unk00[0x10];
};

class TESWaterForm
{
public:
    void* Function3070b0(std::uint32_t a_index);  // compared: 0x3070b0

    std::uint8_t unk00[0x80];
    WaterEntry entry80;  // 80
    WaterEntry entry90;  // 90
    WaterEntry entryA0;  // A0
    WaterEntry entryB0;  // B0
};
static_assert(offsetof(TESWaterForm, entryB0) == 0xb0, "layout");
