// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldDynamicsStepInfo; size 0x140
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkStepInfo.h"
#include "hkpSolverInfo.h"
struct hkpWorldDynamicsStepInfo {
    hkStepInfo stepInfo;
    hkpSolverInfo solverInfo;
};
static_assert(sizeof(hkpWorldDynamicsStepInfo) == 320, "hkpWorldDynamicsStepInfo layout differs from the PDB");
