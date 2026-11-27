// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2b39f0 TESObjectLAND::sub_14025B9B0
// Adapted bodies: none
#include "TESObjectLAND_2b39f0.h"

// Reads a land vertex color as normalized RGBA floats, or returns the default color when unloaded.
void TESObjectLAND::sub_14025B9B0(std::int32_t a_quad, std::int32_t a_vertex, NiColorA& a_out) const
{
    if (!loadedData) {
        a_out = g_defaultLandColor;
        return;
    }
    constexpr float kInv255 = 1.0f / 255.0f;
    a_out.red = static_cast<float>(loadedData->colors[a_quad][a_vertex].r) * kInv255;
    a_out.green = static_cast<float>(loadedData->colors[a_quad][a_vertex].g) * kInv255;
    a_out.blue = static_cast<float>(loadedData->colors[a_quad][a_vertex].b) * kInv255;
    a_out.alpha = 1.0f;
}
