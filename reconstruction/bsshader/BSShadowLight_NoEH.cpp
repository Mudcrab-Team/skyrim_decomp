// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh-root-includes.json
// 0x155c990 BSShadowLight::ReturnShadowmaps
// Adapted bodies: none
#include "BSShadowLight_NoEH.h"

// g_freeShadowmapMask: GUESS(low); a bit per shadowmap slot that is free to hand out
extern std::uint32_t g_freeShadowmapMask;

// ReturnShadowmaps: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowLight::ReturnShadowmaps()
{
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        if (shadowmapDescriptors[i].renderTarget != -1) {
            g_freeShadowmapMask |= 1 << shadowmapDescriptors[i].shadowmapIndex;
            shadowmapDescriptors[i].renderTarget = -1;
            shadowmapDescriptors[i].unkCC = 1.0f;
        }
    }
}
