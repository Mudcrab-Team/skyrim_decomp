// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16_; size 0x40
#pragma once

#include "hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___NodeManager.h"
struct hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___Node;
struct hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___VFTable;
struct hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16 {
    hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___VFTable* vftable_hkAabbTree_0;
    char _pad_8[8];
    hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___Node* m_rootNode_10;
    unsigned short m_rootIdx_18;
    char _pad_1A[2];
    int m_numLeaves_1C;
    hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16___NodeManager m_nodeManager_20;
};
static_assert(sizeof(hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16) == 64, "hkAabbTree_hkAabbTreeData__hkAabbTreeAabb16_uint16 layout differs from the PDB");
