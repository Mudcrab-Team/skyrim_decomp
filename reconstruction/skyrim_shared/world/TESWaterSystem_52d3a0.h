// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterSystem::SetUnderwaterVariables: CRASHLOGGER_PDB(59818@2026.10.24); name only
// TESWaterSystem, unkB8, unkC0, WaterRenderer, WaterRenderer::Function524080, g_waterRenderer, g_isUnderwater: STANDIN GUESS(low); the callee at 0x524080, a renderer pointer and a byte global, read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class WaterRenderer
{
public:
    void Function524080(bool a_underwater);  // callee at 0x524080, not compared here
};

extern WaterRenderer* g_waterRenderer;
extern bool g_isUnderwater;

class TESWaterSystem
{
public:
    void SetUnderwaterVariables(bool a_underwater, float a_value);  // compared: 0x52d3a0

    std::uint8_t unk00[0xb8];
    bool unkB8;  // B8
    std::uint8_t unkB9[7];
    float unkC0;  // C0
};
static_assert(offsetof(TESWaterSystem, unkC0) == 0xc0, "layout");
