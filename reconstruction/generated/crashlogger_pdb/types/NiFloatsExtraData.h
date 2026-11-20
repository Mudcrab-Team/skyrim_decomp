// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFloatsExtraData; size 0x28
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiFloatsExtraData {
    NiExtraData_b2385dce _base;
    unsigned int size;
    unsigned int pad;
    float* value;
};
static_assert(sizeof(NiFloatsExtraData) == 40, "NiFloatsExtraData layout differs from the PDB");
