// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1835f0 ExtraReflectedRefs::IsNotEqual
// Adapted bodies: none
#include "ExtraReflectedRefs_1835f0.h"

bool ExtraReflectedRefs::IsNotEqual(const ExtraReflectedRefs* other) const
{
    if (count != other->count)
        return true;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (data[i] != other->data[i])
            return true;
    }
    return false;
}
