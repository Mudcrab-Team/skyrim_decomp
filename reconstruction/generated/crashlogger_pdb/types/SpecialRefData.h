// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpecialRefData; size 0x18
#pragma once

#include "UnloadedRefData.h"
struct BGSLocationRefType_b7f4d597;
struct SpecialRefData {
    BGSLocationRefType_b7f4d597* type;
    UnloadedRefData refData;
    unsigned int pad14;
};
static_assert(sizeof(SpecialRefData) == 24, "SpecialRefData layout differs from the PDB");
