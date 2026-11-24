// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x755980 PlayerCharacter::BumpCounter755980
// Adapted bodies: none
#include "PlayerCharacter_755980.h"

float gDefaultValue;

void PlayerCharacter::BumpCounter755980()
{
    counter++;
    if (tracked == -1.0f) {
        tracked = gDefaultValue;
    }
}
