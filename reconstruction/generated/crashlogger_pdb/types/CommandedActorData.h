// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CommandedActorData; size 0x10
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
struct ActiveEffect;
struct CommandedActorData {
    BSPointerHandle_RE__Actor_1a35f4b9 commandedActor;
    unsigned int pad04;
    ActiveEffect* activeEffect;
};
static_assert(sizeof(CommandedActorData) == 16, "CommandedActorData layout differs from the PDB");
