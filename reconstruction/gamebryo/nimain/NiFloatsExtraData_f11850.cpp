// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build.
// 0xf11870 NiFloatsExtraData::GetValue
#include "NiFloatsExtraData_f11850.h"

float NiFloatsExtraData::GetValue(std::uint32_t index) const
{
    if (index < size) {
        return value[index];
    }
    return 0.0f;
}
