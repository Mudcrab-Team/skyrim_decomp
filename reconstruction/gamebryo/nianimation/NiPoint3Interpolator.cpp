// Source exposure: mixed (pinned image listing and cited public declarations).
// Code origin: original reconstruction from the pinned instruction listing; no body adapted.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf84ad0 NiPoint3Interpolator::IsEqual
// 0xf84e20 NiPoint3Interpolator::IsPoint3ValueSupported
// Adapted bodies: none
// NiPoint3Interpolator::IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the database name list carries NiPoint3Interpolator::IsEqual_*, and the body compares the point and the key data of the other interpolator
// pose, data, cachedKeyIndex: GUESS(low); members named for the measured accesses: point at 0x18, key data at 0x28, cached index at 0x30
#include "NiPoint3Interpolator.h"

bool NiPoint3Interpolator::IsEqual(NiObject* a_object)
{
    if (!IsEqualInterpolatorBase(*this, a_object)) {
        return false;
    }
    const NiPoint3Interpolator* other = static_cast<NiPoint3Interpolator*>(a_object);
    if (pose.x != other->pose.x || pose.y != other->pose.y || pose.z != other->pose.z) {
        return false;
    }
    if (data) {
        if (!other->data) {
            return false;
        }
        if (!data->IsEqual(other->data)) {
            return false;
        }
    } else if (other->data) {
        return false;
    }
    return true;
}

std::uint8_t NiPoint3Interpolator::IsPoint3ValueSupported() const
{
    return 0x1;
}
