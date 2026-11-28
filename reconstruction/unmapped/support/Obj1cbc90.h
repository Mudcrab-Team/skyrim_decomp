// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Obj1cbc90, GetEntry, count460, entries468: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Obj1cbc90
{
    Obj1cbc90* GetEntry(std::uint32_t a_index);  // compared: 0x1cbc90

    std::uint8_t unk00[0x460];  // 000
    std::uint32_t count460;     // 460
    Obj1cbc90** entries468;     // 468
};
