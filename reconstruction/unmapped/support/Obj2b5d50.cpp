// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2b5d50::Function2b5d50, treated as adapted: shaped like TESObjectLAND::RemoveTextureFromArrays in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesland_od_variant.cpp:3922
// SPDX-License-Identifier: CC0-1.0
// 0x2b5d50 Obj2b5d50::Function2b5d50
#include "Obj2b5d50.h"

// Removes a texture layer from a land quadrant, shifting higher texture slots and vertex alphas down.
void Obj2b5d50::Function2b5d50(std::uint8_t a_quad, std::uint16_t a_layer, LandData2b5d50* a_data)
{
    if (a_quad < 4u && a_layer < 5u && a_data) {
        for (std::size_t i = a_layer; i < 5u; ++i) {
            a_data->textures[a_quad][i] = a_data->textures[a_quad][i + 1u];
        }
        a_data->textures[a_quad][5] = nullptr;
        for (std::uint32_t v = 0; v < 289u; ++v) {
            for (std::uint32_t i = a_layer; i < 5u; ++i) {
                a_data->alpha[a_quad][v][i] = a_data->alpha[a_quad][v][i + 1u];
            }
            a_data->alpha[a_quad][v][5] = 0;
        }
    }
}
