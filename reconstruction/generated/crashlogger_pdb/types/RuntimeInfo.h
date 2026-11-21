// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RuntimeInfo; size 0x8
#pragma once
struct RuntimeInfo {
    int sizeOfExternalRuntime;
    int numSolverResults;
};
static_assert(sizeof(RuntimeInfo) == 8, "RuntimeInfo layout differs from the PDB");
