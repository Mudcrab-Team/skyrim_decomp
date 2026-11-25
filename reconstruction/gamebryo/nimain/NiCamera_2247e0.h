// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPoint3, NiFrustum, NiTransform, NiMatrix3, rotate, translate, scale, world, viewFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCamera, NiPoint3, NiBound, PointInFrustum, BoundInFrustum, center, radius: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "../../generated/crashlogger_pdb/types/NiFrustum.h"
#include "../../generated/crashlogger_pdb/types/NiMatrix3.h"
#include "../../generated/crashlogger_pdb/types/NiPoint3.h"

struct NiTransform
{
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};

class NiBound
{
public:
    NiPoint3 center;
    float radius;
};

class NiCamera
{
public:
    char unknown00[0x7c];
    NiTransform world;
    char unknownB0[0xa0];
    NiFrustum viewFrustum;

    static bool PointInFrustum(const NiPoint3& point, NiCamera* camera, float radius);
    static bool BoundInFrustum(const NiBound& bound, NiCamera* camera);
};
