// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDecalGroup; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct BGSDecalGroup;
struct ExtraDecalGroup {
    BSExtraData_4ca6af76 _base;
    BGSDecalGroup* decalGroup;
};
static_assert(sizeof(ExtraDecalGroup) == 24, "ExtraDecalGroup layout differs from the PDB");
