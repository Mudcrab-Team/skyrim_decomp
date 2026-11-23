// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3f2490 TESTopicInfo::SetAltered
// Adapted bodies: none
#include "TESTopicInfo_3f2490.h"

void TESTopicInfo::SetAltered(bool a_set)
{
    if (!TestBit(formFlags, 14) && a_set && TestBit(formFlags, 3) && owner) {
        owner->SetAltered(true);
    }
    TESForm::SetAltered(a_set);
}
