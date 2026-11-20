// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldDynamicsStepInfo; size 0x140
// one of 2 different PDB types sharing this name
#pragma once

#include "hkStepInfo_751f46fd.h"
#include "hkpSolverInfo_c7ce47cf.h"
struct hkpWorldDynamicsStepInfo_fd1d8780 {
    hkStepInfo_751f46fd stepInfo;
    hkpSolverInfo_c7ce47cf solverInfo;
};
static_assert(sizeof(hkpWorldDynamicsStepInfo_fd1d8780) == 320, "hkpWorldDynamicsStepInfo_fd1d8780 layout differs from the PDB");
