// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueMeter; size 0x50
#pragma once

#include "ActorValue_a2156ae9.h"
#include "HUDMeter.h"
struct ActorValueMeter {
    HUDMeter _base;
    ActorValue_a2156ae9 actorValue;
    unsigned int pad4C;
};
static_assert(sizeof(ActorValueMeter) == 80, "ActorValueMeter layout differs from the PDB");
