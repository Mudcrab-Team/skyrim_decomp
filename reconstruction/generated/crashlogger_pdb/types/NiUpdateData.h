// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiUpdateData; size 0x8
#pragma once

#include "Flag_a4a94b8a.h"
struct NiUpdateData {
    float time;
    Flag_a4a94b8a flags;
};
static_assert(sizeof(NiUpdateData) == 8, "NiUpdateData layout differs from the PDB");
