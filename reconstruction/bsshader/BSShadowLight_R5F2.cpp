// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x15872e0 BSShadowFrustumLight::BSShadowFrustumLight
// CI hash: 0x15872e0 ??0BSShadowFrustumLight@@QEAA@MMMM@Z
// Adapted bodies: none
#include <math.h>

#include "BSShadowLight_R5F2.h"

// BSShadowFrustumLight: CRASHLOGGER_PDB(59818@2026.10.24)
BSShadowFrustumLight::BSShadowFrustumLight(float a_fov, float a_arg2, float a_nearPlane, float a_farPlane)
{
    MemoryContextScope scope(0x1D);
    SetShadowmapCount(1);
    shadowmapDescriptors[0].camera = new NiCamera;
    shadowmapDescriptors[0].cullingProcess = new BSCullingProcess(nullptr);
    shadowmapDescriptors[0].cullingProcess->ignorePreprocess = 1;
    cullingProcess = shadowmapDescriptors[0].cullingProcess;
    shadowmapDescriptors[0].cullingProcess->unk30190 = new CullGeometryList;
    shadowmapDescriptors[0].cullingProcess->camera = shadowmapDescriptors[0].camera;
    unk568 = a_arg2 > 1.0f ? a_arg2 : 1.0f;
    unk56C = a_nearPlane;
    unk570 = a_farPlane;
    // the half angle is kept between one and one hundred sixty degrees, in radians
    float rawAngle = a_fov * 0.5f;
    float cappedAngle = rawAngle < 2.792527f ? rawAngle : 2.792527f;
    unk560 = tanf(cappedAngle > 0.01745329f ? cappedAngle : 0.01745329f);
    unk564 = unk560;
    NiCamera* camera = shadowmapDescriptors[0].camera;
    NiFrustum frustum(false);
    frustum = camera->frustum;
    frustum.left = -unk560;
    frustum.right = unk560;
    frustum.bottom = -unk564;
    frustum.top = unk564;
    frustum.nearPlane = unk56C;
    frustum.farPlane = light ? light->unknown128 : 256.0f;
    camera->SetFrustum(frustum);
}
