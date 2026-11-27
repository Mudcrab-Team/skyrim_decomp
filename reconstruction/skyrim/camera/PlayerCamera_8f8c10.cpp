// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: NiPoint3::operator=, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x8f8c10 PlayerCamera::GetFirstPersonNodePosition_14084B030
#include "PlayerCamera_8f8c10.h"

// Write the first-person camera node's world translation to a_out, or zero if unavailable.
void PlayerCamera::GetFirstPersonNodePosition_14084B030(NiPoint3& a_out) const
{
    if (cameraStates[0] && cameraStates[0]->firstPersonCameraObj) {
        a_out = cameraStates[0]->firstPersonCameraObj->unkA0;
    } else {
        a_out = g_zeroPoint8f8c10;
    }
}
