// Code origin: body written by the contributor from the compared function's behaviour; names and
// declarations come from the header (CharmedBaryon/CommonLibSSE-NG, MIT).
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0x7384e0 BSSimpleScaleController::TargetIsRequiredType
#include "BSSimpleScaleController.h"

// The scale controller only drives NiAVObject targets: walk the target's type chain looking for it.
bool BSSimpleScaleController::TargetIsRequiredType() const
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
