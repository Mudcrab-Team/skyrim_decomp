// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiAVObject, NiFrustum, NiUpdateData, world, worldBound, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect, Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WorldToCamMatrix: GUESS(low)
// 0xeef9a0 NiCamera::Ctor
#include "NiCamera_eef9a0.h"

// Constructs a camera with default frustum, viewport, and initial world transform update.
NiCamera::NiCamera() :
    NiAVObject(),
    viewFrustum(false),
    port(0.0f, 0.0f, 0.0f, 0.0f)
{
    viewFrustum.fNear = 1.0f;
    viewFrustum.fFar = 2.0f;
    viewFrustum.fTop = 0.5f;
    viewFrustum.fBottom = -0.5f;
    viewFrustum.fLeft = -0.5f;
    viewFrustum.fRight = 0.5f;
    viewFrustum.bOrtho = false;
    minNearPlaneDist = 0.1f;
    maxFarNearRatio = 10000.0f;
    port.left = 0.0f;
    port.top = 1.0f;
    port.bottom = 0.0f;
    port.right = 1.0f;
    lodAdjust = 1.0f;

    NiUpdateData updateData{0.0f, 0};
    Update(updateData);
    WorldToCamMatrix();
    worldBound.center.x = world.translate.x;
    worldBound.center.y = world.translate.y;
    worldBound.center.z = world.translate.z;
}
