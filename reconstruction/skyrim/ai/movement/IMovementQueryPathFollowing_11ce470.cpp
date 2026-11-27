// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11ce470 MovementAgentPathFollowerStandard::Function11ce470
// Adapted bodies: none
#include "IMovementQueryPathFollowing_11ce470.h"

// Return whether the follower state equals 9 under the read lock.
bool MovementAgentPathFollowerStandard::Function11ce470()
{
    BSReadLockGuard guard(unkE8);
    return unkF0 == 9;
}
