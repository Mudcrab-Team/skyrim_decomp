// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1581e90 BSShadowDirectionalLight::`scalar deleting destructor'
// CI hash: 0x1581e90 ??_GBSShadowDirectionalLight@@UEAAPEAXI@Z
// Adapted bodies: none
#include "BSShadowDirectionalLight_R4.h"

// ~BSShadowDirectionalLight: CRASHLOGGER_PDB(59818@2026.10.24)
BSShadowDirectionalLight::~BSShadowDirectionalLight()
{
    for (std::uint32_t i = 1; i < shadowMapCount; ++i) {
        shadowmapDescriptors[i].renderTarget = -1;
        shadowmapDescriptors[i].unkCC = 1.0f;
    }
    for (std::uint32_t i = 0; i < cullingProcesses.iSize; ++i) {
        cullingProcesses[i]->unk30190 = nullptr;
        delete cullingProcesses[i];
    }
    cascadeCamera = nullptr;
}
