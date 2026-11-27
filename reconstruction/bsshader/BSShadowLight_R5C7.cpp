// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1587620 BSShadowFrustumLight::BSShadowFrustumLight
// CI hash: 0x1587620 ??0BSShadowFrustumLight@@QEAA@MMMMM@Z
// Adapted bodies: none
#include <math.h>

#include "BSShadowLight_R5C7.h"

// BSShadowFrustumLight: CRASHLOGGER_PDB(59818@2026.10.24)
// The half angles are kept between one and one hundred sixty degrees, in radians.
BSShadowFrustumLight::BSShadowFrustumLight(float a_fovX, float a_fovY, float a_arg3, float a_nearPlane, float a_farPlane)
{
    MemoryContextScope scope(0x1D);
    SetShadowmapCount(1);
    shadowmapDescriptors[0].camera = new NiCamera;
    shadowmapDescriptors[0].cullingProcess = new BSCullingProcess(nullptr);
    shadowmapDescriptors[0].cullingProcess->unk30190 = new CullGeometryList;
    shadowmapDescriptors[0].cullingProcess->camera = shadowmapDescriptors[0].camera;
    unk568 = a_arg3 > 1.0f ? a_arg3 : 1.0f;
    unk56C = a_nearPlane;
    unk570 = a_farPlane;
    float rawX = a_fovX * 0.5f;
    float cappedX = rawX < 2.792527f ? rawX : 2.792527f;
    float halfAngleX = cappedX > 0.01745329f ? cappedX : 0.01745329f;
    unk560 = tanf(halfAngleX);
    float rawY = a_fovY * 0.5f;
    float cappedY = rawY < 2.792527f ? rawY : 2.792527f;
    float halfAngleY = cappedY > 0.01745329f ? cappedY : 0.01745329f;
    unk564 = tanf(halfAngleY);
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
