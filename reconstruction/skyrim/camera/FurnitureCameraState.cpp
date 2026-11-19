// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x8f6960 FurnitureCameraState::GetTranslation
// Adapted bodies: none
#include "FurnitureCameraState.h"

void FurnitureCameraState::GetTranslation(NiPoint3& a_translation)
{
    NiQuaternion rotation;
    GetRotation(rotation);

    NiMatrix3 matrix;
    QuaternionToMatrix(rotation, matrix);

    GetTranslationFromMatrix(a_translation, matrix);
}
