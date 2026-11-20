// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraRagDollData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct RagDollData;
struct ExtraRagDollData {
    BSExtraData_4ca6af76 _base;
    RagDollData* ragDollData;
};
static_assert(sizeof(ExtraRagDollData) == 24, "ExtraRagDollData layout differs from the PDB");
