// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x674250 Actor::QDoubleGravity
// Adapted bodies: none
#include "Actor_674250.h"

bool Actor::QDoubleGravity()
{
    return currentProcess ? static_cast<std::uint16_t>(actorState.Function6e14f0() & 0x481) == 0x81 : false;
}
