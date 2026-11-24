// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x692620 Actor::SetProcessValue692620
// Adapted bodies: none
#include "Actor_692620.h"

void Actor::SetProcessValue692620(float newValue)
{
    ActorProcess* state = process;
    if (state && state->values) {
        state->values->unk1C = newValue;
        state->values->flags |= 0x2000;
    }
}
