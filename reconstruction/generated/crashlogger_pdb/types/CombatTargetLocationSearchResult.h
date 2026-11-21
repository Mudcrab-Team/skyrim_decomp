// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTargetLocationSearchResult; size 0x20
#pragma once

#include "CombatObject_2faf992b.h"
struct CombatTargetLocation;
struct CombatTargetLocationSearch;
struct CombatTargetLocationSearchResult {
    CombatObject_2faf992b _base;
    CombatTargetLocationSearch* search;
    CombatTargetLocation* ans;
};
static_assert(sizeof(CombatTargetLocationSearchResult) == 32, "CombatTargetLocationSearchResult layout differs from the PDB");
