// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten array comparison.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf114c0 NiFloatsExtraData::Functionf114c0
// Adapted bodies: none.
#include "NiFloatsExtraData_f114c0.h"

bool NiFloatsExtraData::Functionf114c0(const NiFloatsExtraData* other) const
{
    if (!other || size != other->size) {
        return false;
    }
    if (value) {
        if (!other->value) {
            return false;
        }
        for (std::uint32_t index = 0; index < size; ++index) {
            if (value[index] != other->value[index]) {
                return false;
            }
        }
    } else if (other->value) {
        return false;
    }
    return true;
}
