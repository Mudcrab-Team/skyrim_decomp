// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body shape adapted from the sibling function below, offsets and type object checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/BSPlayerDistanceCheckController.cpp:115
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x10c17a0 BhkBlendController::TargetIsRequiredType
#include "BhkBlendController_10c17a0.h"

// The controller only drives NiAVObject targets: walk the target's type chain looking for it.
bool BhkBlendController::TargetIsRequiredType() const
{
    if (target != nullptr) {
        for (const NiRTTI* rtti = target->GetRTTI(); rtti != nullptr; rtti = rtti->parent) {
            if (rtti == &NiRTTI_NiAVObject) {
                return true;
            }
        }
    }
    return false;
}
