// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7ab5f0 MovementTweenerAgentNodeFollower::Function7ab5f0
// Adapted bodies: none
#include "MovementTweenerAgentNodeFollower_7ab5f0.h"

void MovementTweenerAgentNodeFollower::Function7ab5f0()
{
    if (unk28) {
        unk28->Unregister(&g_followerKey);
        unk28 = nullptr;
    }
}
