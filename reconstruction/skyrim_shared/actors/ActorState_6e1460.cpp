// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x6e1460 ActorState::ctor
// Adapted bodies: none
#include "ActorState_6e1460.h"

ActorState::ActorState()
{
    actorState1 = 0;
    actorState2.talkingToPlayer = 0;
    actorState2.forceRun = 0;
    actorState2.forceSneak = 0;
    actorState2.headTracking = 1;
    actorState2.reanimating = 0;
    actorState2.weaponState = 0;
    actorState2.wantBlocking = 0;
    actorState2.flightBlocked = 0;
    actorState2.recoil = 0;
    actorState2.allowFlying = 1;
    actorState2.staggered = 0;
    actorState2.unk14 = 0;
}
