// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x186370 ExtraOcclusionPlaneRefData::IsNotEqual
// Adapted bodies: none
#include "ExtraOcclusionPlaneRefData_186370.h"
bool ExtraOcclusionPlaneRefData::IsNotEqual(const ExtraOcclusionPlaneRefData* other) const
{
    const std::uint32_t* a = data;
    const std::uint32_t* b = other->data;
    if (!a && !b) return false;
    if (!a || !b) return true;
    for (std::int64_t i = 0; i < 4; ++i) {
        if (a[i] != b[i]) return true;
    }
    return false;
}
