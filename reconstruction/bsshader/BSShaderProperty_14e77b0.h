// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty, SetLightState: CRASHLOGGER_PDB(59818@2026.10.24)
// lightData, lastRenderPassState: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShaderPropertyLightData, activeLightMask: CRASHLOGGER_PDB(59818@2026.10.24); BSShaderPropertyLightData is a stand-in
// ClearLights, EnableLight: GUESS(low)
// unk00, unk38: GUESS(low); padding in front of the members the function touches
#pragma once

#include <cstdint>
#include <cstddef>

struct BSShaderPropertyLightData
{
    unsigned char unk00[0x1C];
    // Clears every light slot and reports whether any was set.
    bool ClearLights()
    {
        std::uint32_t previous = activeLightMask;
        activeLightMask = 0;
        return previous != 0;
    }

    void EnableLight(int a_slot) { activeLightMask |= 1 << a_slot; }

    std::uint32_t activeLightMask;
};

class BSShaderProperty
{
public:
    void SetLightState(int a_state);

    unsigned char unk00[0x34];
    int lastRenderPassState;
    unsigned char unk38[0x38];
    BSShaderPropertyLightData* lightData;
};
static_assert(offsetof(BSShaderProperty, lightData) == 0x70, "lightData offset");
