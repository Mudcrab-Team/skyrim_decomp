// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x55c740 DragonCameraState::Begin
// 0x55c770 DragonCameraState::End
// 0x55c7a0 DragonCameraState::GetFreeRotationMode
// 0x55cbb0 DragonCameraState::SetCameraHandle
// 0x55d460 DragonCameraState::~DragonCameraState
// Adapted bodies: none
#include "DragonCameraState.h"

// The constructor emits the class vftables; the empty inline destructor in the header lets the
// compiler emit the scalar deleting destructor compared at 0x55d460.
DragonCameraState::DragonCameraState()
{
}

void DragonCameraState::Begin()
{
    ThirdPersonState::Begin();
    unknownEC = 0.0f;
}

void DragonCameraState::End()
{
    ThirdPersonState::End();
    unknownF0 = 0;
}

bool DragonCameraState::GetFreeRotationMode() const
{
    return (g_playerCharacterSingleton->unkFlagsBED & 0x4) == 0
        && (freeRotationEnabled || g_dragonCameraGate->unk4B != 0);
}

void DragonCameraState::SetCameraHandle(RefHandle& a_handle)
{
    cameraHandle = a_handle;
}
