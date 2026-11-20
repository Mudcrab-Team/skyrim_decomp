// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCombatStyle; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "CombatStyleCloseRangeData.h"
#include "CombatStyleFlightData.h"
#include "CombatStyleGeneralData.h"
#include "CombatStyleLongRangeData.h"
#include "CombatStyleMeleeData.h"
#include "FLAG_92fc0a0b.h"
#include "TESForm.h"
struct TESCombatStyle_cff5b770 {
    TESForm _base;
    CombatStyleGeneralData generalData;
    CombatStyleMeleeData meleeData;
    CombatStyleCloseRangeData closeRangeData;
    CombatStyleLongRangeData longRangeData;
    CombatStyleFlightData flightData;
    FLAG_92fc0a0b flags;
};
static_assert(sizeof(TESCombatStyle_cff5b770) == 160, "TESCombatStyle_cff5b770 layout differs from the PDB");
