// Near miss: 74.1% | register-schedule
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build, using the cited accessors.
// Adapted bodies: none
// 0x241120 TESObjectWEAP::IsRangedWithoutAmmo
#include "include/241120/TESObjectWEAP_241120.h"

// Guess: a ranged weapon that fires no ammunition, which leaves the staff.
// The PDB records no return type; the compared code returns a bool.
bool TESObjectWEAP::IsRangedWithoutAmmo() const
{
    return IsRanged() && !IsBow() && !IsCrossbow();
}
