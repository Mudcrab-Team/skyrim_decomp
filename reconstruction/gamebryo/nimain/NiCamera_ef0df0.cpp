// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiPoint3, WorldPtToScrPt, worldToCam, port: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xef0df0 NiCamera::WorldPtToScrPt
#include "NiCamera_ef0df0.h"

// Projects a world-space point into the camera viewport, returning false if clipped.
bool NiCamera::WorldPtToScrPt(const NiPoint3& in, float& xOut, float& yOut, float zeroTolerance) const
{
    float w = in.x * worldToCam[3][0] + in.y * worldToCam[3][1] + in.z * worldToCam[3][2] + worldToCam[3][3];
    if (w <= zeroTolerance) {
        return false;
    }

    float invW = 1.0f / w;
    xOut = in.x * worldToCam[0][0] + in.y * worldToCam[0][1] + in.z * worldToCam[0][2] + worldToCam[0][3];
    yOut = in.y * worldToCam[1][1] + in.x * worldToCam[1][0] + in.z * worldToCam[1][2] + worldToCam[1][3];
    xOut *= invW;
    yOut *= invW;

    if (xOut < -1.0f || xOut > 1.0f || yOut < -1.0f || yOut > 1.0f) {
        return false;
    }

    xOut *= (port.right - port.left) * 0.5f;
    yOut *= (port.top - port.bottom) * 0.5f;
    xOut += (port.right + port.left) * 0.5f;
    yOut += (port.top + port.bottom) * 0.5f;
    return true;
}
