// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11ce540 MovementAgentPathFollowerStandard::Function11ce540
// Adapted bodies: none
#include "IMovementQueryPathFollowing_11ce540.h"

// Return whether the follower state equals 4 or 13 under the read lock.
bool MovementAgentPathFollowerStandard::Function11ce540()
{
    BSReadLockGuard guard(unkE8);
    return unkF0 == 4 || unkF0 == 13;
}
