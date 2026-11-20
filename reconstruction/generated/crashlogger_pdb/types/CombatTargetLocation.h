// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTargetLocation; size 0x38
#pragma once

#include "CombatObject_2faf992b.h"
#include "NiPoint3.h"
struct CombatTargetLocation {
    CombatObject_2faf992b _base;
    unsigned int field_10;
    unsigned int field_14;
    float angle[4];
    NiPoint3 V;
    unsigned int pad34;
};
static_assert(sizeof(CombatTargetLocation) == 56, "CombatTargetLocation layout differs from the PDB");
