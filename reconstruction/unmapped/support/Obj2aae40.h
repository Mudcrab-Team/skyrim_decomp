// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2aae40::Function2aae40, treated as adapted: shaped like TESObjectLAND::GetDefaultTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:1916
// SPDX-License-Identifier: CC0-1.0
// LandData2aae40, Obj2aae40, Obj2aae40::Function2aae40: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LandData2aae40
{
    std::uint8_t unk00[0x1230];     // 0x0000
    std::uint8_t alpha[4][289][6];  // 0x1230
};

class Obj2aae40
{
public:
    float Function2aae40(std::int32_t a_quad, std::int32_t a_vertex) const;

    std::uint8_t unk00[0x40];      // 0x00
    const LandData2aae40* data40;  // 0x40
};

static_assert(offsetof(LandData2aae40, alpha) == 0x1230, "alpha offset");
static_assert(offsetof(Obj2aae40, data40) == 0x40, "data40 offset");
