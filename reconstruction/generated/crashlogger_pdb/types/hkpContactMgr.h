// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactMgr; size 0x18
#pragma once

struct hkReferencedObject__VFTable;
struct hkpContactMgr {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    int m_type_10;
    char _pad_14[4];
};
static_assert(sizeof(hkpContactMgr) == 24, "hkpContactMgr layout differs from the PDB");
