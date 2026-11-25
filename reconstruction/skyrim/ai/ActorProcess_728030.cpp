// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x728030 ActorProcess::RefreshActorExtra
// Adapted bodies: none
#include "ActorProcess_728030.h"

void ActorProcess::RefreshActorExtra(Actor* a_actor, bool a_value)
{
    if (!a_actor) {
        return;
    }

    const std::uint32_t now = GetTickCount();
    const std::uint64_t nextTime = middleHigh ? middleHigh->nextUpdateTime : 0xFFFFFFFFu;
    if (now >= nextTime) {
        a_actor->UpdateExtra(a_value);
        if (middleHigh) {
            middleHigh->nextUpdateTime = now + 1000;
        }
    }
}
