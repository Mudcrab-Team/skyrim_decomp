// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkConstraintInternal; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "hkBool.h"
#include "hkEnum_hkpConstraintInstance__ConstraintPriority_uint8.h"
struct hkpConstraintAtom;
struct hkpConstraintInstance;
struct hkpEntity_b3bc9432;
struct hkConstraintInternal_4023762f {
    hkpConstraintInstance* m_constraint_0;
    hkpEntity_b3bc9432* m_entities_8[2];
    hkpConstraintAtom* m_atoms_18;
    unsigned short m_atomsSize_20;
    unsigned char m_callbackRequest_22;
    hkEnum_hkpConstraintInstance__ConstraintPriority_uint8 m_priority_23;
    unsigned short m_sizeOfSchemas_24;
    unsigned short m_numSolverResults_26;
    unsigned short m_numSolverElemTemps_28;
    unsigned char m_whoIsMaster_2A;
    hkBool m_isNormalType_2B;
    char _pad_2C[4];
    void* m_runtime_30;
    unsigned short m_runtimeSize_38;
    unsigned short m_slaveIndex_3A;
    char _pad_3C[4];
};
static_assert(sizeof(hkConstraintInternal_4023762f) == 64, "hkConstraintInternal_4023762f layout differs from the PDB");
