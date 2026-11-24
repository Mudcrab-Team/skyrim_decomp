// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x675b90 Character::UpdateWeaponDrawRequest
// Adapted bodies: none
#include "Character_675b90.h"

void Character::UpdateWeaponDrawRequest()
{
    WEAPON_STATE state = GetWeaponState();
    if (state == WEAPON_STATE::kWantToDraw || state == WEAPON_STATE::kWantToSheathe) {
        DrawWeaponMagicHands(GetWeaponState() == WEAPON_STATE::kWantToDraw);
    }
}
