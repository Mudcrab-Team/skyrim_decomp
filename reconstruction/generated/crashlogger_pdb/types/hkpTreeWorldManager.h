// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTreeWorldManager; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16;
struct hkKdTree;
struct hkReferencedObject__VFTable;
struct hkpTreeWorldManager {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    int m_type_10;
    char _pad_14[4];
    hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16* m_inactiveTree_18;
    hkKdTree* m_kdTree_20;
};
static_assert(sizeof(hkpTreeWorldManager) == 40, "hkpTreeWorldManager layout differs from the PDB");
