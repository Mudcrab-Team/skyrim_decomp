// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2aae40::Function2aae40, treated as adapted: shaped like TESObjectLAND::GetDefaultTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:1916
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2aae40 Obj2aae40::Function2aae40
#include "Obj2aae40.h"

// Returns the remaining base texture alpha weight (1 minus the five overlay layers) at a vertex.
float Obj2aae40::Function2aae40(std::int32_t a_quad, std::int32_t a_vertex) const
{
    if (a_quad < 4 && a_vertex < 289 && data40) {
        float sum = static_cast<float>(data40->alpha[a_quad][a_vertex][0]) +
            static_cast<float>(data40->alpha[a_quad][a_vertex][1]) +
            static_cast<float>(data40->alpha[a_quad][a_vertex][2]) +
            static_cast<float>(data40->alpha[a_quad][a_vertex][3]) +
            static_cast<float>(data40->alpha[a_quad][a_vertex][4]);
        return 1.0f - sum / 255.0f;
    }
    return 0.0f;
}
