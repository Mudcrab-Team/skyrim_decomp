// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpImpulseLimitBreachedElem; size 0x20
#pragma once

struct hkpConstraintInstance;
struct hkpSolverResults;
struct hkpImpulseLimitBreachedElem {
    unsigned short m_type_0;
    unsigned short m_isContact_2;
    char _pad_4[4];
    hkpConstraintInstance* m_constraintInstance_8;
    hkpSolverResults* m_solverResult_10;
    char _pad_18[8];
};
static_assert(sizeof(hkpImpulseLimitBreachedElem) == 32, "hkpImpulseLimitBreachedElem layout differs from the PDB");
