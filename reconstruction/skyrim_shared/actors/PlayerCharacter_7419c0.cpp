// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7419c0 PlayerCharacter::SetHighFlag7419c0
// Adapted bodies: none
#include "PlayerCharacter_7419c0.h"

void PlayerCharacter::SetHighFlag7419c0(bool value)
{
    if (flagByte.flag != value) {
        flagByte.flag = value;
    }
}
