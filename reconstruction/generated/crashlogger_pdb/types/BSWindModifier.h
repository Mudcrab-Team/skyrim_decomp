// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWindModifier; size 0x38
#pragma once

#include "NiPSysModifier.h"
struct BSWindModifier {
    NiPSysModifier _base;
    float strength;
    unsigned int pad34;
};
static_assert(sizeof(BSWindModifier) == 56, "BSWindModifier layout differs from the PDB");
