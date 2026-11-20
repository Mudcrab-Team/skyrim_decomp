// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAction; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
struct hkpSimulationIsland;
struct hkpWorld;
struct hkpAction_085cde55 {
    hkReferencedObject _base;
    hkpWorld* world;
    hkpSimulationIsland* island;
    unsigned long long userData;
    hkStringPtr_33d8e88b name;
};
static_assert(sizeof(hkpAction_085cde55) == 48, "hkpAction_085cde55 layout differs from the PDB");
