// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, UpdateLightPlanes, NiCamera, NiPlane, NiPoint3, camera, lightCamera, lightPosition, lightRadius, activePlanes, equatorialPlane, unk301F8: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAVObject, world, rotate, translate, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include "NiAVObject.h"

struct NiCamera : NiAVObject {};

struct NiPlane {
    NiPoint3 normal;
    float constant;
    NiPlane(const NiPoint3& normal, const NiPoint3& point);
};

struct BSParabolicCullingProcess {
    unsigned char unrecovered00[0x18];
    NiCamera* camera;
    unsigned char unrecovered20[0x7C];
    unsigned int activePlanes;
    unsigned char unrecoveredA0[0x301F8 - 0xA0];
    float unk301F8;
    unsigned char unrecovered1FC[12];
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiPointer<NiCamera> lightCamera;
    void UpdateLightPlanes(NiCamera* newCamera, float radius, bool rememberCamera);
};
