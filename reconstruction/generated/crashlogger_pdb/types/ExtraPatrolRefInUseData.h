// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPatrolRefInUseData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct ExtraPatrolRefInUseData {
    BSExtraData_4ca6af76 _base;
    unsigned int user;
    unsigned int pad14;
};
static_assert(sizeof(ExtraPatrolRefInUseData) == 24, "ExtraPatrolRefInUseData layout differs from the PDB");
