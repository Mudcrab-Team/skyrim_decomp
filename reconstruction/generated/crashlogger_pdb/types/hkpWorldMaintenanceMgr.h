// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldMaintenanceMgr; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkReferencedObject__VFTable;
struct hkpWorldMaintenanceMgr {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
};
static_assert(sizeof(hkpWorldMaintenanceMgr) == 16, "hkpWorldMaintenanceMgr layout differs from the PDB");
