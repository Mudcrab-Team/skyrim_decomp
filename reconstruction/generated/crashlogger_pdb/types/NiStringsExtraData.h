// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiStringsExtraData; size 0x28
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiStringsExtraData {
    NiExtraData_b2385dce _base;
    unsigned int size;
    unsigned int pad1C;
    unsigned char** value;
};
static_assert(sizeof(NiStringsExtraData) == 40, "NiStringsExtraData layout differs from the PDB");
