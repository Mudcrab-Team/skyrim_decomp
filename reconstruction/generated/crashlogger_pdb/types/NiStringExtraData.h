// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiStringExtraData; size 0x20
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiStringExtraData {
    NiExtraData_b2385dce _base;
    unsigned char* value;
};
static_assert(sizeof(NiStringExtraData) == 32, "NiStringExtraData layout differs from the PDB");
