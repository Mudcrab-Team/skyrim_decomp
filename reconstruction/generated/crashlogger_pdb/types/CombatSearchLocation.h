// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatSearchLocation; size 0x20
#pragma once

#include "AITimeStamp.h"
#include "BGSWorldLocation.h"
struct CombatSearchLocation {
    BGSWorldLocation loc;
    AITimeStamp timestamp;
    float unk20;
};
static_assert(sizeof(CombatSearchLocation) == 32, "CombatSearchLocation layout differs from the PDB");
