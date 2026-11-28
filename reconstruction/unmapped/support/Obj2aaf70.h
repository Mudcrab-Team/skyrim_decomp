// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2aaf70::Function2aaf70, treated as adapted: shaped like TESObjectLAND::SetTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:2019
// SPDX-License-Identifier: CC0-1.0
// LandData2aaf70, Obj2aaf70, Obj2aaf70::Function2aaf70: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LandData2aaf70
{
    std::uint8_t unk00[0x1230];     // 0x0000
    std::uint8_t alpha[4][289][6];  // 0x1230
};

class Obj2aaf70
{
public:
    void Function2aaf70(std::uint8_t a_quad, std::uint16_t a_vertex, std::uint16_t a_layer, float a_alpha);

    std::uint8_t unk00[0x40];  // 0x00
    LandData2aaf70* data40;    // 0x40
};

static_assert(offsetof(LandData2aaf70, alpha) == 0x1230, "alpha offset");
static_assert(offsetof(Obj2aaf70, data40) == 0x40, "data40 offset");
