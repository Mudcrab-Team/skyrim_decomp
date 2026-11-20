// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorState; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "ActorState1.h"
#include "ActorState2.h"
#include "IMovementState.h"
struct ActorState_877c2eb1 {
    IMovementState _base;
    ActorState1 actorState1;
    ActorState2 actorState2;
};
static_assert(sizeof(ActorState_877c2eb1) == 16, "ActorState_877c2eb1 layout differs from the PDB");
