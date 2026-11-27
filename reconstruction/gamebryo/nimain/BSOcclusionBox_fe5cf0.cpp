// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionBox, BSOcclusionShape, NiPoint3, NiMatrix3, translation, rotation, visibilityState, size, boundShape, facePlaneSlots, silhouetteCount: CRASHLOGGER_PDB(59818@2026.10.24)
// kZeroPoint, kIdentityMatrix: GUESS(low)
// 0xfe5cf0 BSOcclusionBox::BSOcclusionBox
#include "BSOcclusionBox_fe5cf0.h"

BSOcclusionBox::BSOcclusionBox()
{
    translation = NiPoint3::kZeroPoint;
    size = NiPoint3(50.0f, 50.0f, 50.0f);
    rotation = NiMatrix3::kIdentityMatrix;
    visibilityState = 0;
    boundShape = nullptr;
    silhouetteCount = 0;
    for (int i = 0; i < 6; ++i) {
        facePlaneSlots[i] = -1;
    }
}
