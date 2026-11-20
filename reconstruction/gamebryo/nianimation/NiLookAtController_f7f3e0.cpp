// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf7f3e0 NiLookAtController::LinkObject
// 0xf7f420 NiLookAtController::RegisterStreamables
// 0xf7fc20 NiLookAtController::dtor
// 0xf7fc80 NiLookAtController::TargetIsRequiredType
#include "NiLookAtController_f7f3e0.h"

// ReadStreamObjectLink: GUESS(low); returns the resolved link read from the stream.
NiObject* ReadStreamObjectLink(NiStream& stream);

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiLookAtController::NiLookAtController() = default;

void NiLookAtController::LinkObject(NiStream& stream)
{
    NiTimeController::LinkObject(stream);
    lookAt = ReadStreamObjectLink(stream);
}

bool NiLookAtController::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiTimeController::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (lookAt) {
        lookAt->RegisterStreamables(stream);
    }
    return true;
}

bool NiLookAtController::TargetIsRequiredType() const
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
