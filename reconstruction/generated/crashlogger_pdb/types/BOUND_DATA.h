// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BOUND_DATA; size 0xc
#pragma once

#include "NiNPShortPoint3.h"
struct BOUND_DATA {
    NiNPShortPoint3 boundMin;
    NiNPShortPoint3 boundMax;
};
static_assert(sizeof(BOUND_DATA) == 12, "BOUND_DATA layout differs from the PDB");
