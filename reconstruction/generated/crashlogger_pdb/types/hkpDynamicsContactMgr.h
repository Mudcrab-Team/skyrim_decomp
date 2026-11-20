// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpDynamicsContactMgr; size 0x20
#pragma once

struct hkReferencedObject__VFTable;
struct hkpWorld_938ebb10;
struct hkpDynamicsContactMgr {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    int m_type_10;
    char _pad_14[4];
    hkpWorld_938ebb10* m_world_18;
};
static_assert(sizeof(hkpDynamicsContactMgr) == 32, "hkpDynamicsContactMgr layout differs from the PDB");
