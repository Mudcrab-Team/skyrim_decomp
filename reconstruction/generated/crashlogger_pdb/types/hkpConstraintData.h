// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkReferencedObject__VFTable;
struct hkpConstraintData {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned long long m_userData_10;
};
static_assert(sizeof(hkpConstraintData) == 24, "hkpConstraintData layout differs from the PDB");
