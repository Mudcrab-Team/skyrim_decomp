// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x2bf750 TESObjectCELL::GetCantWaitHere
// Adapted bodies: none
#include "TESObjectCELL_2bf750.h"

// Return whether waiting is disallowed in this cell or its parent worldspace.
bool TESObjectCELL::GetCantWaitHere() const
{
    if ((cellFlags & 1) != 0) {
        if ((formFlags & 0x80000) != 0) {
            return true;
        }
        return false;
    }
    if (worldSpace) {
        return worldSpace->DisallowsWaiting();
    }
    return false;
}
