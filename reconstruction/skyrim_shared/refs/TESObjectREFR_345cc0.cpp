// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x345cc0 TESObjectREFR::Function345cc0
// Adapted bodies: none
#include "TESObjectREFR_345cc0.h"

bool TESObjectREFR::Function345cc0(TESObjectREFR* refr)
{
    bool found = false;
    EnterRefListLock(&gRefListLock);
    if (refr) {
        for (RefListNode* node = &gRefListBb8; node; node = node->next) {
            if (node->ref == refr) {
                found = true;
                break;
            }
        }
    }
    LeaveRefListLock(&gRefListLock);
    return found;
}
