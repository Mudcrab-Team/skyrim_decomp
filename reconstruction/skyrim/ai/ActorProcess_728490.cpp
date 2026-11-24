// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x728490 ActorProcess::VisitActorPerks
// Adapted bodies: none
#include "ActorProcess_728490.h"

void ActorProcess::VisitActorPerks(Actor* a_actor)
{
    if (middleHigh && a_actor->baseForm) {
        ActorPerkVisitor visitor(a_actor);
        a_actor->baseForm->perkRanks.VisitPerks(&visitor);
    }
}
