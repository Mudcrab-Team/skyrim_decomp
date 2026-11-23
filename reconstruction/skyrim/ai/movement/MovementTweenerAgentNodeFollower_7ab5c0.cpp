// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7ab5c0 MovementTweenerAgentNodeFollower::Function7ab5c0
// Adapted bodies: none
#include "MovementTweenerAgentNodeFollower_7ab5c0.h"

void MovementTweenerAgentNodeFollower::Function7ab5c0(Target* a_target)
{
    unk28 = a_target;
    a_target->Register(&g_followerKey, unk20);
}
