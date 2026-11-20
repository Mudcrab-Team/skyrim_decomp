// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkConstraintInternal; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpConstraintAtom_c2cbad9c;
struct hkpConstraintInstance_7e571b14;
struct hkpConstraintRuntime;
struct hkpEntity;
struct hkConstraintInternal {
    hkpConstraintInstance_7e571b14* constraint;
    hkpEntity* entities[2];
    hkpConstraintAtom_c2cbad9c* atoms;
    unsigned short atomsSize;
    unsigned char callbackRequest;
    unsigned char priority;  // ConstraintPriority in the PDB is wider than this slot
    unsigned short sizeOfSchemas;
    unsigned short numSolverResults;
    unsigned short numSolverElemTemps;
    unsigned char whoIsMaster;
    bool isNormalType;
    unsigned char undefined_2c[4];
    hkpConstraintRuntime* runtime;
    unsigned short runtimeSize;
    unsigned short slaveIndex;
    unsigned char undefined_3c[4];
};
static_assert(sizeof(hkConstraintInternal) == 64, "hkConstraintInternal layout differs from the PDB");
