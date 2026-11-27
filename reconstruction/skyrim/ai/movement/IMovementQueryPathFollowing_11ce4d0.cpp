// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11ce4d0 MovementAgentPathFollowerStandard::Function11ce4d0
// Adapted bodies: none
#include "IMovementQueryPathFollowing_11ce4d0.h"

// Return whether the follower state is an active path-following state under the read lock.
bool MovementAgentPathFollowerStandard::Function11ce4d0()
{
    BSReadLockGuard guard(unkE8);
    bool result;
    switch (unkF0) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 13:
        result = true;
        break;
    default:
        result = false;
        break;
    }
    return result;
}
