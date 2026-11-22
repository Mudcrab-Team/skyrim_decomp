// Build sse-steam-1-7-104. Source exposure: mixed (community headers; the pinned image listing).
// Labels: v2
// Code origin: reconstructed from local instruction listings of the pinned image; bodies adapted from community sources are listed above (none).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RVA 0x8f5310 FirstPersonState::GetTranslation, 78 bytes
// RVA 0x8f56a0 FirstPersonState::LoadGame, 151 bytes
// Evidence: findings/movement-unit-supply-selection.md
// Drafted by claude-sonnet-5-5
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json; GetTranslation and LoadGame are compared.
#include "FirstPersonState.h"

void FirstPersonState::GetTranslation(NiPoint3& a_translation)
{
    const NiAVObject* cameraObj = firstPersonCameraObj;
    if (cameraObj) {
        a_translation.x = cameraObj->worldTranslate.x;
        a_translation.y = cameraObj->worldTranslate.y;
        a_translation.z = cameraObj->worldTranslate.z;
    } else {
        a_translation.x = niPointZero.x;
        a_translation.y = niPointZero.y;
        a_translation.z = niPointZero.z;
    }
}

void FirstPersonState::LoadGame(BGSLoadFormBuffer* a_buf)
{
    a_buf->LoadDataEndian(&sittingRotation, 4, 4);
    if (a_buf->GetVersion() >= 0x15) {
        a_buf->LoadDataEndian(&unk6C, 4, 4);
        a_buf->LoadDataEndian(&unk70, 4, 4);
        a_buf->LoadDataEndian(&unk89, 1, 1);
        a_buf->LoadDataEndian(&unk8A, 1, 1);
    }
}
