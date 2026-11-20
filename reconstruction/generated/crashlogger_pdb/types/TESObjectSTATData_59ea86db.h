// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectSTATData; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_a4a94b8a.h"
struct BGSMaterialObject_dec4aa42;
struct TESObjectSTATData_59ea86db {
    float materialThresholdAngle;
    unsigned int pad04;
    BGSMaterialObject_dec4aa42* materialObj;
    Flag_a4a94b8a flags;
    unsigned int pad14;
};
static_assert(sizeof(TESObjectSTATData_59ea86db) == 24, "TESObjectSTATData_59ea86db layout differs from the PDB");
