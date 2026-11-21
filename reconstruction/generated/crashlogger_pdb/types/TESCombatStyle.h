// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCombatStyle; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESCombatStyle_FLAG.h"
#include "TESCombatStyle__CombatStyleCloseRangeData.h"
#include "TESCombatStyle__CombatStyleFlightData.h"
#include "TESCombatStyle__CombatStyleGeneralData.h"
#include "TESCombatStyle__CombatStyleLongRangeData.h"
#include "TESCombatStyle__CombatStyleMeleeData.h"
#include "TESFileContainer_70f0bdf4.h"
struct TESCombatStyle__VFTable;
struct TESCombatStyle {
    TESCombatStyle__VFTable* vftable_TESCombatStyle_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESCombatStyle__CombatStyleGeneralData GeneralData_20;
    TESCombatStyle__CombatStyleMeleeData MeleeData_48;
    TESCombatStyle__CombatStyleCloseRangeData CloseRangeData_68;
    TESCombatStyle__CombatStyleLongRangeData LongRangeData_78;
    TESCombatStyle__CombatStyleFlightData FlightData_7C;
    TESCombatStyle_FLAG CombatStyleFlags_9C;
};
static_assert(sizeof(TESCombatStyle) == 160, "TESCombatStyle layout differs from the PDB");
