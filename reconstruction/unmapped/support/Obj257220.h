// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj257220::SwapEndian, treated as adapted: shaped like a record byte swap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:12009
// SPDX-License-Identifier: CC0-1.0
// Obj257220, SwapEndian, unk00, unk04, unk08, unk10, unk12, unk14, unk18, unk1C, unk20, unk24, unk28, unk2A, unk2C, unk30: GUESS(low)
#pragma once

#include <cstdint>

class Obj257220
{
public:
    void SwapEndian();

    std::uint32_t unk00;  // 00
    std::uint16_t unk04;  // 04
    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint16_t unk10;  // 10
    std::uint16_t unk12;  // 12
    std::uint32_t unk14;  // 14
    std::uint32_t unk18;  // 18
    std::uint32_t unk1C;  // 1C
    std::uint32_t unk20;  // 20
    std::uint32_t unk24;  // 24
    std::uint16_t unk28;  // 28
    std::uint16_t unk2A;  // 2A
    std::uint16_t unk2C;  // 2C
    std::uint32_t unk30;  // 30
};
