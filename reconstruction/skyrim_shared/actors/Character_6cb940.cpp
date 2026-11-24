// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6cb940 Character::IsInAttackState
// Adapted bodies: none
#include "Character_6cb940.h"

bool Character::IsInAttackState() const
{
    bool result = false;
    ATTACK_STATE_ENUM state = GetAttackState();
    if (state >= ATTACK_STATE_ENUM::kDraw && state <= ATTACK_STATE_ENUM::kHit) {
        result = true;
    } else if (state == ATTACK_STATE_ENUM::kBash) {
        result = true;
    } else if (state >= ATTACK_STATE_ENUM::kBowDraw && state <= ATTACK_STATE_ENUM::kBowReleased) {
        result = true;
    }
    return result;
}
