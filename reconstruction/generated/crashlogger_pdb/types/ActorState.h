// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorState; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "ActorState1.h"
#include "ActorState2.h"
struct ActorState__VFTable;
struct ActorState {
    ActorState__VFTable* vftable_ActorState_0;
    ActorState1 actorState1;
    ActorState2 actorState2;
};
static_assert(sizeof(ActorState) == 16, "ActorState layout differs from the PDB");
