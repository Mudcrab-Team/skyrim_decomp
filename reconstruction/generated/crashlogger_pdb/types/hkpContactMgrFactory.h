// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactMgrFactory; size 0x10
#pragma once

struct hkReferencedObject__VFTable;
struct hkpContactMgrFactory {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
};
static_assert(sizeof(hkpContactMgrFactory) == 16, "hkpContactMgrFactory layout differs from the PDB");
