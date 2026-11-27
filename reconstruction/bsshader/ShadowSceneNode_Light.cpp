// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x150f580 ShadowSceneNode::SetCloudLight
// 0x150f3d0 ShadowSceneNode::SetSunLight
// CI hash: 0x150f3d0 ?SetSunLight@ShadowSceneNode@@QEAAXPEAVNiLight@@@Z
// CI hash: 0x150f580 ?SetCloudLight@ShadowSceneNode@@QEAAXPEAVNiLight@@@Z
#include "ShadowSceneNode_Light.h"

// g_defaultLightColor: GUESS(low); the colour a light node starts with when the caller gives none
extern const NiColor g_defaultLightColor;

// SetCloudLight: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::SetCloudLight(NiLight* a_light)
{
    if (cloudLight) {
        delete cloudLight;
        cloudLight = nullptr;
    }
    if (a_light) {
        cloudLight = new BSLight;
    } else {
        a_light = new NiLight;
        a_light->ambient = g_defaultLightColor;
        a_light->diffuse = g_defaultLightColor;
        cloudLight = new BSLight;
    }
    cloudLight->Unk_02(a_light);
}

// SetSunLight: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::SetSunLight(NiLight* a_light)
{
    if (sunLight) {
        delete sunLight;
        sunLight = nullptr;
    }
    if (a_light) {
        sunLight = new BSLight;
        sunLight->Unk_02(a_light);
        if (shadowDirLight) {
            shadowDirLight->Unk_02(a_light);
        }
    } else {
        a_light = new NiLight;
        a_light->ambient = g_defaultLightColor;
        a_light->diffuse = g_defaultLightColor;
        sunLight = new BSLight;
        sunLight->Unk_02(a_light);
    }
}
