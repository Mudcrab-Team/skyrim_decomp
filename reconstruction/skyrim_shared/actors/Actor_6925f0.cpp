// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6925f0 Actor::SetProcessValue6925f0
// Adapted bodies: none
#include "Actor_6925f0.h"

void Actor::SetProcessValue6925f0(float newValue)
{
    ActorProcess* state = process;
    if (state && state->values) {
        state->values->unk18 = newValue;
        state->values->flags |= 0x1000;
    }
}
