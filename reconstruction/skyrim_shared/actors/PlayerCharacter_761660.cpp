// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x761660 PlayerCharacter::Function761660
// Adapted bodies: none
#include "PlayerCharacter_761660.h"

bool PlayerCharacter::Function761660()
{
    if (unkF8 && gProcessQueryEnabled) {
        return QueryProcess(unkF8);
    }
    return false;
}
