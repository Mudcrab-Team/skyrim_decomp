// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2b5d50::Function2b5d50, treated as adapted: shaped like TESObjectLAND::RemoveTextureFromArrays in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:3922
// SPDX-License-Identifier: CC0-1.0
// LandData2b5d50, Obj2b5d50, Obj2b5d50::Function2b5d50: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LandData2b5d50
{
    std::uint8_t unk00[0x1230];     // 0x0000
    std::uint8_t alpha[4][289][6];  // 0x1230
    std::uint8_t unk2D48[0x1B68];   // 0x2D48
    void* textures[4][6];           // 0x48B0
};

class Obj2b5d50
{
public:
    static void Function2b5d50(std::uint8_t a_quad, std::uint16_t a_layer, LandData2b5d50* a_data);
};

static_assert(offsetof(LandData2b5d50, alpha) == 0x1230, "alpha offset");
static_assert(offsetof(LandData2b5d50, textures) == 0x48B0, "textures offset");
