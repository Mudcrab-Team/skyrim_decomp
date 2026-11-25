// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3bfc00 TESNPC::IsHeadPartAvailable
// Adapted bodies: none
#include "TESNPC_3bfc00.h"

bool TESNPC::IsHeadPartAvailable(BGSHeadPart* a_headPart)
{
    if (a_headPart && a_headPart->IsValidForRace(race)) {
        if (IsFemale() == 0 ? IsBitClear(a_headPart->flags, 2) : IsBitClear(a_headPart->flags, 1)) {
            return true;
        }
    }
    return false;
}
