// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x155c4b0 BSShadowLight::BSShadowLight
// CI hash: 0x155c4b0 ??0BSShadowLight@@QEAA@XZ
// Adapted bodies: none
#include "BSShadowLight_R5C1.h"

// g_unitShadowBias: GUESS(low); the default shadow bias scale the constructor stores
extern const float g_unitShadowBias;

// BSShadowLight: CRASHLOGGER_PDB(59818@2026.10.24)
BSShadowLight::BSShadowLight()
{
    tail.projectedBoundingBox.left = 0;
    tail.projectedBoundingBox.right = 0;
    tail.projectedBoundingBox.top = 0;
    tail.projectedBoundingBox.bottom = 0;
    tail.drawFocusShadows = false;
    shadowMapCount = 0;
    shadowmapIndex = 0xFF;
    tail.shadowBiasScale = g_unitShadowBias;
}
