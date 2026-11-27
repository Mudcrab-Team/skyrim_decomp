// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1228580 MovementPathFollowing1228580::Func4_141113220
// Adapted bodies: none
#include "IMovementQueryPathFollowing_1228580.h"

// Return whether the path-following state is 1 or 2 under the read lock.
bool MovementPathFollowing1228580::Func4_141113220()
{
    BSReadLockGuard guard(unk78);
    return unk10 == 1 || unk10 == 2;
}
