// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiIntegersExtraData; size 0x28
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiIntegersExtraData {
    NiExtraData_b2385dce _base;
    unsigned int size;
    unsigned int pad;
    int* value;
};
static_assert(sizeof(NiIntegersExtraData) == 40, "NiIntegersExtraData layout differs from the PDB");
