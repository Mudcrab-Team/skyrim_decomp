// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiPoint3, WorldPtToScreenPt3: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xef1180 NiCamera::WorldPtToScreenPt3
#include "NiCamera_ef1180.h"

#include <cmath>

// Projects a world-space point into viewport coordinates and normalized depth.
bool NiCamera::WorldPtToScreenPt3(
    const float matrix[4][4],
    const NiRect<float>& port,
    const NiPoint3& in,
    float& xOut,
    float& yOut,
    float& zOut,
    float zeroTolerance)
{
    float w = std::fabs(in.x * matrix[3][0] + in.y * matrix[3][1] + in.z * matrix[3][2] + matrix[3][3]);
    if (w > zeroTolerance) {
        float invW = 1.0f / w;
        xOut = in.y * matrix[0][1] + in.x * matrix[0][0] + in.z * matrix[0][2] + matrix[0][3];
        yOut = in.y * matrix[1][1] + in.x * matrix[1][0] + in.z * matrix[1][2] + matrix[1][3];
        xOut *= invW;
        yOut *= invW;

        xOut *= (port.right - port.left) * 0.5f;
        yOut *= (port.top - port.bottom) * 0.5f;
        xOut += (port.left + port.right) * 0.5f;
        yOut += (port.bottom + port.top) * 0.5f;

        zOut = (in.y * matrix[2][1] + in.x * matrix[2][0] + in.z * matrix[2][2] + matrix[2][3]) * invW;
        return true;
    }

    return false;
}
