// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x345c50 TESObjectREFR::Function345c50
// Adapted bodies: none
#include "TESObjectREFR_345c50.h"

bool TESObjectREFR::Function345c50(TESObjectREFR* refr)
{
    bool found = false;
    EnterRefListLock(&gRefListLock);
    if (refr) {
        for (RefListNode* node = &gRefListBc8; node; node = node->next) {
            if (node->ref == refr) {
                found = true;
                break;
            }
        }
    }
    LeaveRefListLock(&gRefListLock);
    return found;
}
