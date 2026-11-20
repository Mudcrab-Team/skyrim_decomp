// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpViolatedConstraintArray; size 0x408
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpConstraintInstance;
struct hkpViolatedConstraintArray {
    unsigned int m_nextFreeElement_0;
    char _pad_4[4];
    hkpConstraintInstance* m_constraints_8[128];
};
static_assert(sizeof(hkpViolatedConstraintArray) == 1032, "hkpViolatedConstraintArray layout differs from the PDB");
