// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x8fc4f0 BleedoutCameraState::~BleedoutCameraState
// Adapted bodies: none
#include "BleedoutCameraState.h"

// Defined so that the compiler emits the vftable and, beside it, the deleting destructor that is
// compared. The destructor body is empty; the vftable stores, the animatedBone release and the
// base destructor call come from the declared class layout.
BleedoutCameraState::BleedoutCameraState()
{
}

BleedoutCameraState::~BleedoutCameraState()
{
}
