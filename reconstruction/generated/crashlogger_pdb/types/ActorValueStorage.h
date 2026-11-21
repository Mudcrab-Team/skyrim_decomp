// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueStorage; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "LocalMap_RE__Modifiers_32bd1fc2.h"
#include "LocalMap_float_c321f6b4.h"
struct ActorValueStorage {
    LocalMap_float_c321f6b4 baseValues;
    LocalMap_RE__Modifiers_32bd1fc2 modifiers;
};
static_assert(sizeof(ActorValueStorage) == 32, "ActorValueStorage layout differs from the PDB");
