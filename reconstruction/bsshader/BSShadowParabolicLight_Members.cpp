// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh-root-includes.json
// 0x1588c80 BSShadowParabolicLight::Render
// 0x1588dc0 BSShadowParabolicLight::dtor_deleting
// Adapted bodies: none
#include "BSShadowParabolicLight_Members.h"

// g_parabolicSide, g_parabolicRadius: GUESS(low); globals the cascade render reads for the current face
extern float g_parabolicSide;
extern float g_parabolicRadius;

// Render: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowParabolicLight::Render(void* a_arg)
{
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        float side;
        if (i == 1) {
            shadowmapDescriptors[1].renderTarget = shadowmapDescriptors[0].renderTarget;
            side = -1.0f;
        } else {
            side = 1.0f;
        }
        g_parabolicSide = side;
        g_parabolicRadius = light->unknown128;
        RenderCascade(&shadowmapDescriptors[i], a_arg, 0);
        g_parabolicRadius = -1.0f;
    }
}

BSShadowParabolicLight::~BSShadowParabolicLight()
{
    if (shadowMapCount == 2) {
        shadowmapDescriptors[1].renderTarget = -1;
    }
}
