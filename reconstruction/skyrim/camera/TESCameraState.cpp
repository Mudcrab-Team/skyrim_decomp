// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x24a090 TESCameraState::Update
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// TESCameraState::Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "TESCameraState.h"
#include <intrin.h>

void TESCameraState::Update(NextStateHandle& a_nextState)
{
    RefCountedState* state = a_nextState.ptr;
    if (!state)
        return;
    a_nextState.ptr = nullptr;
    // The count is shared across threads; the last releaser owns deletion.
    if (_InterlockedExchangeAdd(&state->refCount, -1) == 1)
        delete state;
}

void TESCameraState::GetRotation(NiQuaternion& a_rotation)
{
    a_rotation = niQuatDefault;
}

void TESCameraState::GetTranslation(NiPoint3& a_translation)
{
    a_translation.x = niPointZero.x;
    a_translation.y = niPointZero.y;
    a_translation.z = niPointZero.z;
}

void TESCameraState::Begin()
{
}

void TESCameraState::End()
{
}

void TESCameraState::LoadGame(BGSLoadFormBuffer*)
{
}
