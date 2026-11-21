// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatAimController; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimer.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "CombatObject_2faf992b.h"
#include "NiPoint3.h"
#include "PRIORITY.h"
#include "enumeration_RE__CombatAimController__Flags_unsigned_int_0da645ab.h"
struct CombatController;
struct MagicCaster;
struct CombatAimController {
    CombatObject_2faf992b _base;
    MagicCaster* mcaster;
    NiPoint3 P;
    unsigned int field_24;
    CombatController* combat_control;
    BSPointerHandle_RE__Actor_1a35f4b9 target;
    PRIORITY priority1;
    PRIORITY priority2;
    enumeration_RE__CombatAimController__Flags_unsigned_int_0da645ab flags;
    AITimer timer;
};
static_assert(sizeof(CombatAimController) == 72, "CombatAimController layout differs from the PDB");
