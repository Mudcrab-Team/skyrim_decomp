// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatAimController; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimer.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "CombatObject.h"
#include "NiPoint3_a7124070.h"
#include "PRIORITY.h"
#include "enumeration_RE__CombatAimController__Flags_unsigned_int_0da645ab.h"
struct CombatController_f906bf3b;
struct MagicCaster_274caf29;
struct CombatAimController_af40e787 {
    CombatObject _base;
    MagicCaster_274caf29* mcaster;
    NiPoint3_a7124070 P;
    unsigned int field_24;
    CombatController_f906bf3b* combat_control;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    PRIORITY priority1;
    PRIORITY priority2;
    enumeration_RE__CombatAimController__Flags_unsigned_int_0da645ab flags;
    AITimer timer;
};
static_assert(sizeof(CombatAimController_af40e787) == 72, "CombatAimController_af40e787 layout differs from the PDB");
