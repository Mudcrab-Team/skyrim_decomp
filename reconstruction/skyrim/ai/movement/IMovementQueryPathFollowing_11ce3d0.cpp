// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11ce3d0 MovementAgentPathFollowerStandard::Function11ce3d0
// Adapted bodies: none
#include "IMovementQueryPathFollowing_11ce3d0.h"

// Return whether the path follower has finished or reached the end of its current path segment.
bool MovementAgentPathFollowerStandard::Function11ce3d0()
{
    BSReadLockGuard guard(unkE8);
    return unkF0 == 0 || unkF0 == 12 ||
           (unkF0 == 10 && unkF8 && unk100 && unkF8->unk90 > 0.0f && unk100->unk8C == unk100->unk80 - 1);
}
