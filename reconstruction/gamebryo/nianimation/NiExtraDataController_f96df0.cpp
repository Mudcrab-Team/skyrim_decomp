// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf96df0 NiExtraDataController::LinkObject
// 0xf96e40 NiExtraDataController::RegisterStreamables
// 0xf96e90 NiExtraDataController::SaveBinary
// 0xf97260 NiExtraDataController::ctor
#include "NiExtraDataController_f96df0.h"

#include "NiStream.h"

// LinkStreamString, SaveStreamString: GUESS(low); forward the named extra-data key.
void LinkStreamString(NiStream& stream, BSFixedString& name);
void SaveStreamString(NiStream& stream, const BSFixedString& name);

void NiExtraDataController::LinkObject(NiStream& stream)
{
    NiSingleInterpController::LinkObject(stream);
    return LinkStreamString(stream, extraDataName);
}

bool NiExtraDataController::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiSingleInterpController::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    stream.RegisterFixedString(extraDataName);
    return true;
}

void NiExtraDataController::SaveBinary(NiStream& stream)
{
    NiSingleInterpController::SaveBinary(stream);
    return SaveStreamString(stream, extraDataName);
}

NiExtraDataController::NiExtraDataController()
{
    extraDataName.text = nullptr;
    extraData = nullptr;
}
