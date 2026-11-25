// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSRenderPass, SetLights, BSLight, numLights, sceneLights: CRASHLOGGER_PDB(59818@2026.10.24)
// maxLights: GUESS(low)
// 0x1555390 BSRenderPass::SetLights
#include "BSRenderPass_1555390.h"

// Copy the active lights and clear the remaining slots.
void BSRenderPass::SetLights(unsigned char count, BSLight** lights)
{
    numLights = count;
    for (unsigned char i = 0; i < count; ++i) {
        sceneLights[i] = lights[i];
    }
    for (unsigned char i = count; i < maxLights; ++i) {
        sceneLights[i] = nullptr;
    }
}
