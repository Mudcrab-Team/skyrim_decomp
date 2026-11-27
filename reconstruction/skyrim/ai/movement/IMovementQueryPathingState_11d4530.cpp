// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11d4530 MovementPathingState11d4530::Func11_1410C1B10
// Adapted bodies: none
#include "IMovementQueryPathingState_11d4530.h"

// Return whether an active pathing request exists with state 1 or 2 under the read lock.
bool MovementPathingState11d4530::Func11_1410C1B10()
{
    BSReadLockGuard guard(unk48);
    bool result = unk30 && (unk28 == 1 || unk28 == 2);
    return result;
}
