// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x75e170 PlayerCharacter::Function75e170
// Adapted bodies: none
#include "PlayerCharacter_75e170.h"

void PlayerCharacter::Function75e170()
{
    PlayerCharacter* player = gPlayerSingleton;
    gPlayerLocation.x = player->unk54.x;
    gPlayerLocation.y = player->unk54.y;
    gPlayerLocation.z = player->unk54.z;
}
