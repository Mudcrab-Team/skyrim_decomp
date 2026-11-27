// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf3d7b0 NiUnionBV::RemoveAllChildren
// Adapted bodies: none
#include "NiUnionBV_f3d7b0.h"

void NiUnionBV::RemoveAllChildren()
{
    for (std::uint32_t i = 0; i < count; ++i) {
        delete children[i];
    }
    for (std::uint16_t i = 0; i < count; ++i) {
        children[i] = nullptr;
    }
    count = 0;
    elementCount = 0;
}
