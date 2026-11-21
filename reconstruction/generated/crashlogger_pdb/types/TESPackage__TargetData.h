// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__TargetData; size 0x18
#pragma once

#include "TESPackage__TargetStore.h"
struct TESPackage__TargetData {
    char TargetType_0;
    char _pad_1[7];
    TESPackage__TargetStore Target_8;
    int Value_10;
    char _pad_14[4];
};
static_assert(sizeof(TESPackage__TargetData) == 24, "TESPackage__TargetData layout differs from the PDB");
