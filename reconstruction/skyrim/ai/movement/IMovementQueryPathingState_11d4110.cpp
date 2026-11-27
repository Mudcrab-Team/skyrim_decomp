// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x11d4110 MovementPathingState11d4110::Func4_1410C1720
// Adapted bodies: none
#include "IMovementQueryPathingState_11d4110.h"

// Map the matching request state to a tri-state query result: 1 for state 0, 0 for states 1-3, 2 otherwise.
std::uint32_t MovementPathingState11d4110::Func4_1410C1720(const PathRequestHandle11d4110& a_handle)
{
    BSReadLockGuard guard(unk48);
    std::uint32_t result = 2;
    if (unk30 == a_handle.ptr) {
        switch (unk28) {
        case 0:
            result = 1;
            break;
        case 1:
        case 2:
        case 3:
            result = 0;
            break;
        default:
            break;
        }
    }
    return result;
}
