// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2aaf70::Function2aaf70, treated as adapted: shaped like TESObjectLAND::SetTexturePercent in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:2019
// SPDX-License-Identifier: CC0-1.0
// 0x2aaf70 Obj2aaf70::Function2aaf70
#include "Obj2aaf70.h"

// Stores a normalized alpha weight for a land quadrant, vertex, and texture layer.
// A value of zero or less stores zero. A value above 1 is not clamped; the byte conversion
// holds only for values up to 1.
void Obj2aaf70::Function2aaf70(std::uint8_t a_quad, std::uint16_t a_vertex, std::uint16_t a_layer, float a_alpha)
{
    if (a_quad < 4u && a_vertex < 289u && a_layer < 5u && data40) {
        if (a_alpha > 0.0f) {
            data40->alpha[a_quad][a_vertex][a_layer] = static_cast<std::uint8_t>(a_alpha * 255.0f);
        } else {
            data40->alpha[a_quad][a_vertex][a_layer] = 0;
        }
    }
}
