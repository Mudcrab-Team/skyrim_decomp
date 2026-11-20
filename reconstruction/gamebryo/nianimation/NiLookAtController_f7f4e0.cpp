// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf7f4e0 NiLookAtController::IsEqual
// Adapted bodies: none
#include "NiLookAtController_f7f4e0.h"

// CompareTimeControllers: GUESS(low)
bool CompareTimeControllers(NiTimeController& controller, NiObject* object);

bool NiLookAtController::IsEqual(NiObject* object)
{
    if (!CompareTimeControllers(*this, object)) {
        return false;
    }
    auto* other = static_cast<NiLookAtController*>(object);
    auto* localData = lookAt;
    auto* otherData = other->lookAt;
    if (localData) {
        if (!otherData || !localData->IsEqual(otherData)) {
            return false;
        }
    } else if (otherData) {
        return false;
    }
    return true;
}
