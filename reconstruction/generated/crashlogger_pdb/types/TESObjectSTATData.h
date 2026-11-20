// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectSTATData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__TESObjectSTATData__Flag_unsigned_int_0500c3a2.h"
struct BGSMaterialObject;
struct TESObjectSTATData {
    float materialThresholdAngle;
    unsigned int pad04;
    BGSMaterialObject* materialObj;
    EnumSet_RE__TESObjectSTATData__Flag_unsigned_int_0500c3a2 flags;
    unsigned int pad14;
};
static_assert(sizeof(TESObjectSTATData) == 24, "TESObjectSTATData layout differs from the PDB");
