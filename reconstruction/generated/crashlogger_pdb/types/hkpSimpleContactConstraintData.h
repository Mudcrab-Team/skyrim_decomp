// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleContactConstraintData; size 0x50
#pragma once

struct hkReferencedObject__VFTable;
struct hkpConstraintInstance;
struct hkpSimpleContactConstraintAtom;
struct hkpSimpleContactConstraintData__VFTable;
struct hkpSimpleContactConstraintData {
    hkpSimpleContactConstraintData__VFTable* vftable_hkpSimpleContactConstraintData_0;
    hkReferencedObject__VFTable* vftable_hkReferencedObject_8;
    unsigned short m_memSizeAndFlags_10;
    short m_referenceCount_12;
    char _pad_14[4];
    unsigned long long m_userData_18;
    char _pad_20[16];
    void* m_clientData_30;
    hkpConstraintInstance* m_constraint_38;
    hkpSimpleContactConstraintAtom* m_atom_40;
    int m_atomSize_48;
    char _pad_4C[4];
};
static_assert(sizeof(hkpSimpleContactConstraintData) == 80, "hkpSimpleContactConstraintData layout differs from the PDB");
