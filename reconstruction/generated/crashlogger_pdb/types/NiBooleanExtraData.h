// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBooleanExtraData; size 0x20
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiBooleanExtraData {
    NiExtraData_b2385dce _base;
    bool data;
    unsigned char undefined_19[7];
};
static_assert(sizeof(NiBooleanExtraData) == 32, "NiBooleanExtraData layout differs from the PDB");
