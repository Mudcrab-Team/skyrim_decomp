// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the community declarations and the pinned listing only; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf614b0 NiFloatInterpolator::IsEqual
// 0xf61760 NiFloatInterpolator::IsFloatValueSupported
// 0xf61810 NiFloatInterpolator::GetKeyType
// Adapted bodies: none
#include "NiFloatInterpolator.h"

bool NiFloatInterpolator::IsEqual(NiObject* a_object)
{
    if (!IsEqualBase(a_object)) {
        return false;
    }

    // The stand-in is flat, so the downcast to the compared interpolator goes through a void pointer.
    auto* interpolator = static_cast<NiFloatInterpolator*>(static_cast<void*>(a_object));

    if (floatValue != interpolator->floatValue) {
        return false;
    }

    NiFloatData* data = floatData;
    NiFloatData* otherData = interpolator->floatData;

    if (data) {
        if (!otherData) {
            return false;
        }
        if (data->IsEqual(otherData)) {
            return true;
        }
        return false;
    }

    if (otherData) {
        return false;
    }

    return true;
}

bool NiFloatInterpolator::IsFloatValueSupported() const
{
    return true;
}

KeyType NiFloatInterpolator::GetKeyType(std::uint16_t a_channel) const
{
    return KeyType::kNoInterp;
}
