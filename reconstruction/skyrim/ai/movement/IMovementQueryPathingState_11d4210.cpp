// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11d4210 MovementPathingState11d4210::Func6_1410C1820
// Adapted bodies: none
#include "IMovementQueryPathingState_11d4210.h"

// Return 1 if the active request matches a_handle and its state is 1; otherwise return 0.
std::uint32_t MovementPathingState11d4210::Func6_1410C1820(const PathRequestHandle11d4210& a_handle)
{
    BSReadLockGuard guard(unk48);
    std::uint32_t result = 0;
    if (unk30 == a_handle.ptr && unk28 == 1) {
        result = 1;
    }
    return result;
}
