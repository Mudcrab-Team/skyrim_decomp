// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x9ff790 Actor::HasPerk9ff790
// Adapted bodies: none
#include "Actor_9ff790.h"
bool Actor::HasPerk9ff790(VM* vm, unsigned int stackId, Actor* actor, Perk* perk)
{
    bool result = false;
    if (perk) {
        result = actor->Function69f920(*perk) != 0;
    } else {
        vm->LogError(perkError, stackId, 2);
    }
    return result;
}
