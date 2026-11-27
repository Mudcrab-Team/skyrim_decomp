// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh-root-includes.json
// 0x157ed20 BSShadowDirectionalLight::ReturnShadowmaps
// 0x157ea50 BSShadowDirectionalLight::TransformClipSpacePlanes
// 0x15819c0 BSShadowDirectionalLight::UpdateSunDirection
// Adapted bodies: none
#include "BSShadowDirectionalLight_Members.h"

// TransformPlanes: GUESS(low); the out-of-line transform of one descriptor's clip planes
void TransformPlanes(const void* a_arg1, const void* a_arg2, NiPlane* a_planes);

// g_sunDirectionStep, g_sunDirectionSpeed: GUESS(low); tunables that pace the sun direction blend
extern float g_sunDirectionStep;
extern float g_sunDirectionSpeed;

// GetSunDirection: GUESS(low); fills the current sun direction
void GetSunDirection(NiPoint3* a_out);

// ReturnShadowmaps, TransformClipSpacePlanes: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowDirectionalLight::ReturnShadowmaps()
{
    for (std::uint32_t i = 1; i < shadowMapCount; ++i) {
        shadowmapDescriptors[i].renderTarget = -1;
        shadowmapDescriptors[i].unkCC = 1.0f;
    }
    BSShadowLight::ReturnShadowmaps();
}

void BSShadowDirectionalLight::TransformClipSpacePlanes(const void* a_arg1, const void* a_arg2)
{
    if (!unk0D0) {
        for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
            TransformPlanes(a_arg1, a_arg2, shadowmapDescriptors[i].clipPlanes);
        }
        unk0D0 = 1;
    }
}

// UpdateSunDirection: GUESS(low); no public name
void BSShadowDirectionalLight::UpdateSunDirection(NiPoint3* a_out)
{
    float time = sunDirectionTime;
    if (time > 1.0f || sunDirectionMode == 1) {
        GetSunDirection(a_out);
        sunDirection = *a_out;
        sunDirectionTime = 0.0f;
    } else {
        float speed = g_sunDirectionSpeed > 0.000001f ? g_sunDirectionSpeed : 0.000001f;
        sunDirectionTime = g_sunDirectionStep / speed + time;
        *a_out = sunDirection;
    }
}
