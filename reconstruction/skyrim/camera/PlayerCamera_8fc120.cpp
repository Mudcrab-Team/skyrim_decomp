// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: NiPoint3::operator=, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8fc120 PlayerCamera::sub_14084E150
#include "PlayerCamera_8fc120.h"

// Return the stored offset vector from the first-person camera state, or zero if absent.
NiPoint3 PlayerCamera::sub_14084E150() const
{
    NiPoint3 result = g_zeroPoint8fc120;
    if (cameraStates[0]) {
        result = cameraStates[0]->unk48;
    }
    return result;
}
