// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2ac1d0::GetVertexAlpha and Function2ac1d0, treated as adapted: shaped like TESObjectLAND::GetTextureUsePercent and TESObjectLAND::GetTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:711
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:1968
// SPDX-License-Identifier: CC0-1.0
// LandData2ac1d0, Obj2ac1d0, Obj2ac1d0::Function2ac1d0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LandData2ac1d0
{
    std::uint8_t unk00[0x1230];     // 0x0000
    std::uint8_t alpha[4][289][6];  // 0x1230
    std::uint8_t unk2D48[0x1B68];   // 0x2D48
    const void* textures[4][6];     // 0x48B0
};

class Obj2ac1d0
{
public:
    float GetVertexAlpha(std::uint8_t a_quad, std::uint16_t a_vertex, std::uint16_t a_layer) const
    {
        float result = 0.0f;
        if (a_quad < 4u && a_vertex < 289u && a_layer < 5u && data40) {
            result = static_cast<float>(data40->alpha[a_quad][a_vertex][a_layer]) / 255.0f;
        }
        return result;
    }

    float Function2ac1d0(std::uint8_t a_quad, std::uint16_t a_layer) const;

    std::uint8_t unk00[0x40];      // 0x00
    const LandData2ac1d0* data40;  // 0x40
};

static_assert(offsetof(LandData2ac1d0, alpha) == 0x1230, "alpha offset");
static_assert(offsetof(LandData2ac1d0, textures) == 0x48B0, "textures offset");
static_assert(offsetof(Obj2ac1d0, data40) == 0x40, "data40 offset");
