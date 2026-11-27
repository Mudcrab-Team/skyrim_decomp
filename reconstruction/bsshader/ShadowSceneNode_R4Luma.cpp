// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x150f930 ShadowSceneNode::GetLuminanceAtPoint
// Adapted bodies: none
#include "ShadowSceneNode_R4Luma.h"

// GetLuminanceAtPoint: CRASHLOGGER_PDB(59818@2026.10.24); the parameter names are guesses
float ShadowSceneNode::GetLuminanceAtPoint(const NiPoint3& a_point, std::uint32_t& a_lightCount, float& a_ambient, float& a_diffuse, NiLight* a_ignore, std::uint32_t a_shadowMask)
{
    float luminance = 0.0f;
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* light = *it;
        if (light) {
            luminance += light->GetLuminanceAtPoint(a_point, a_ignore);
            if (luminance > 0.0f) {
                ++a_lightCount;
            }
        }
    }
    std::uint32_t bit = 1;
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* light = *it;
        if (light && (a_shadowMask & bit)) {
            luminance += light->GetLuminanceAtPoint(a_point, a_ignore);
            if (luminance > 0.0f) {
                ++a_lightCount;
            }
        }
        bit <<= 1;
    }
    NiLight* sun = sunLight->light;
    a_ambient = (sun->ambient.red + sun->ambient.green + sun->ambient.blue) * (1.0f / 3.0f);
    const NiColor diffuse = sun->diffuse;
    a_diffuse = (diffuse.red + diffuse.green + diffuse.blue) * sun->radius * (1.0f / 3.0f);
    return luminance;
}
