// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf69f40 NiTransformController::IsValidTransformTarget
// 0xf69f90 NiTransformController::SupportsBlendValue
#include "NiTransformController_f69f40.h"

bool NiTransformController::IsValidTransformTarget(const NiObjectNET* target) const
{
    if (target) {
        for (auto* rtti = target->GetRTTI(); rtti; rtti = rtti->baseRTTI) {
            if (rtti == &NiRTTI_NiAVObject) {
                return true;
            }
        }
    }
    return false;
}

bool NiTransformController::SupportsBlendValue(const TransformValueSupport* input, std::uint16_t) const
{
    return input->IsTransformValueSupported();
}
