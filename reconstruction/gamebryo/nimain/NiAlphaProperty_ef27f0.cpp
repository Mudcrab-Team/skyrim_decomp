// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten body from authorized target observations.
// SPDX-License-Identifier: CC0-1.0
// 0xef27f0 NiAlphaProperty::CopyMembers
// Adapted bodies: none.
#include "NiAlphaProperty_ef27f0.h"

void NiAlphaProperty::CopyMembers(NiAlphaProperty* destination, NiCloningProcess& cloning)
{
    NiProperty::CopyMembers(destination, cloning);
    destination->alphaFlags = alphaFlags;
    destination->alphaThreshold = alphaThreshold;
}
