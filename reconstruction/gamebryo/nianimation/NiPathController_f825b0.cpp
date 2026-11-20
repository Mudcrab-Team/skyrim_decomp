// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf825b0 NiPathController::RegisterStreamables
// 0xf83160 NiPathController::ProcessClone
// 0xf847a0 NiPathController::TargetIsRequiredType
// Adapted bodies: none
#include "NiPathController_f825b0.h"

// ProcessTimeControllerClone: GUESS(low)
void ProcessTimeControllerClone(NiTimeController& controller, NiCloningProcess& cloning);

bool NiPathController::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiTimeController::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (pathData) {
        pathData->RegisterStreamables(stream);
    }
    if (percentData) {
        percentData->RegisterStreamables(stream);
    }
    return true;
}

void NiPathController::ProcessClone(NiCloningProcess& cloning)
{
    ProcessTimeControllerClone(*this, cloning);
    if (pathData) {
        pathData->ProcessClone(cloning);
    }
    if (percentData) {
        percentData->ProcessClone(cloning);
    }
}

bool NiPathController::TargetIsRequiredType() const
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
