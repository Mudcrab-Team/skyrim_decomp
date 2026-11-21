// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf62de0 NiSingleInterpController::CopyMembers
// 0xf62e60 NiSingleInterpController::LoadBinary
// 0xf62f60 NiSingleInterpController::IsEqual
// 0xf63110 NiSingleInterpController::Ctor
// Adapted bodies: none
#include "NiSingleInterpController_f62de0.h"

NiTimeRangeInterpolator* CloneInterpolator(NiTimeRangeInterpolator& source, NiCloningProcess& cloning);

void NiSingleInterpController::CopyMembers(NiSingleInterpController* dest, NiCloningProcess& cloning)
{
    NiInterpController::CopyMembers(dest, cloning);
    if (interpolator.pointer) {
        dest->interpolator.Reset(CloneInterpolator(*interpolator.pointer, cloning));
    }
}

void NiSingleInterpController::LoadBinary(NiStream& stream)
{
    NiInterpController::LoadBinary(stream);
    interpolator.Reset(static_cast<NiTimeRangeInterpolator*>(ReadStreamObjectLink(stream)));
}

bool NiSingleInterpController::IsEqual(NiObject* object)
{
    if (!NiInterpController::IsEqual(object)) {
        return false;
    }
    auto* other = static_cast<NiSingleInterpController*>(object);
    auto* localData = interpolator.pointer;
    auto* otherData = other->interpolator.pointer;
    if (localData) {
        if (!otherData || !localData->IsEqual(otherData)) {
            return false;
        }
    } else if (otherData) {
        return false;
    }
    return true;
}

NiSingleInterpController::NiSingleInterpController()
{

}
