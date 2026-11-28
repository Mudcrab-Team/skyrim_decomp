// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x8ff2a0 TweenMenuCameraState::ctor
#include "TweenMenuCameraState_8ff2a0.h"

// Construct TweenMenuCameraState with identity initial rotation and zeroed state fields.
TweenMenuCameraState::TweenMenuCameraState(TESCamera* a_camera, std::uint32_t a_id) :
    TESCameraState8ff2a0(a_camera, a_id),
    initialRotation(gIdentityQuat),
    unk30(0),
    currentRotation(gZeroPoint2),
    targetRotation(gZeroPoint2)
{
    unk44 = 0;
    unk48 = 0;
    unk4C = false;
}
