// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x86a770 Character::sub_1407BE6E0
// Adapted bodies: none
#include "Character_86a770.h"

// Query the character's local bounds data and apply it to the target argument.
void Character::sub_1407BE6E0(void* a_arg) const
{
    BoundsData86a770 data;
    GetBoundsData(data);
    data.Apply(a_arg);
}
