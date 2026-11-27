// Source exposure: mixed (pinned-image observations; community-generated declarations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xef81a0 NiTimeController::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiTimeController_ef81a0.h"

bool NiTimeController::IsEqual(NiObject* other)
{
    if (!NiObject::IsEqual(other))
        return false;
    auto controller = static_cast<NiTimeController*>(other);
    if (flags != controller->flags || frequency != controller->frequency ||
        Phase_18 != controller->Phase_18 || LoKeyTime_1C != controller->LoKeyTime_1C ||
        HiKeyTime_20 != controller->HiKeyTime_20)
        return false;
    if (Target_38) {
        if (!controller->Target_38)
            return false;
    } else if (controller->Target_38) {
        return false;
    }
    return true;
}
