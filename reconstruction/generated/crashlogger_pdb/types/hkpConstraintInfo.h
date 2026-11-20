// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintInfo; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkpConstraintInfo {
    int maxSizeOfSchema;
    int sizeOfSchemas;
    int numSolverResults;
    int numSolverElemTemps;
};
static_assert(sizeof(hkpConstraintInfo) == 16, "hkpConstraintInfo layout differs from the PDB");
