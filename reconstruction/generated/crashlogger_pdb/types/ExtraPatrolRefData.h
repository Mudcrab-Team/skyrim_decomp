// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPatrolRefData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct PatrolRefData;
struct ExtraPatrolRefData {
    BSExtraData_4ca6af76 _base;
    PatrolRefData* patrolData;
};
static_assert(sizeof(ExtraPatrolRefData) == 24, "ExtraPatrolRefData layout differs from the PDB");
