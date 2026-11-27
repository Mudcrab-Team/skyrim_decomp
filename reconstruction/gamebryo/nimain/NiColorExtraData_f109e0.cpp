// Source exposure: mixed (labelled declarations; pinned image observations).
// Code origin: original; handwritten from observed behavior
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf109e0 NiColorExtraData::CopyMembers
#include "NiColorExtraData_f109e0.h"

// Copies the inherited extra-data state and the color payload.
void NiColorExtraData::CopyMembers(NiColorExtraData* destination, NiCloningProcess& cloning)
{
    NiExtraData::CopyMembers(destination, cloning);
    destination->color = color;
}
