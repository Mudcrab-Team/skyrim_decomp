// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorCause; size 0x18
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "NiPoint3.h"
struct ActorCause {
    BSPointerHandle_RE__Actor_1a35f4b9 actor;
    NiPoint3 origin;
    unsigned int actorCauseID;
    int refCount;
};
static_assert(sizeof(ActorCause) == 24, "ActorCause layout differs from the PDB");
