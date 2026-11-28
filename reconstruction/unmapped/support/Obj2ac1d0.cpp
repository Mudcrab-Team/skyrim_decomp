// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2ac1d0::GetVertexAlpha and Function2ac1d0, treated as adapted: shaped like TESObjectLAND::GetTextureUsePercent and TESObjectLAND::GetTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:711
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:1968
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2ac1d0 Obj2ac1d0::Function2ac1d0
#include "Obj2ac1d0.h"

// Sums the normalized vertex alpha weights across a quadrant for one texture layer.
float Obj2ac1d0::Function2ac1d0(std::uint8_t a_quad, std::uint16_t a_layer) const
{
    float total = 0.0f;
    if (a_quad < 4u && a_layer < 5u && data40 && data40->textures[a_quad][a_layer]) {
        for (std::uint16_t v = 0; v < 289u; ++v) {
            total += GetVertexAlpha(a_quad, v, a_layer);
        }
    }
    return total;
}
