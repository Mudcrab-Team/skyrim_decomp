// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2599b0::Obj2599b0, treated as adapted: shaped like TESRegionPointList::TESRegionPointList in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.cpp:293
// SPDX-License-Identifier: CC0-1.0
// Obj2599b0, unk00, unk08, unk10, flag, minX, minY, maxX, maxY, unk2C, unk30: GUESS(low)
#pragma once

#include <cstdint>

class Obj2599b0
{
public:
    explicit Obj2599b0(bool a_flag);

    void* unk00;          // 00
    void* unk08;          // 08
    void* unk10;          // 10
    bool flag;            // 18
    float minX;           // 1C
    float minY;           // 20
    float maxX;           // 24
    float maxY;           // 28
    std::uint32_t unk2C;  // 2C
    std::uint32_t unk30;  // 30
};
