// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldObject; size 0xd0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_hkpProperty_hkContainerHeapAllocator.h"
#include "hkMultiThreadCheck.h"
#include "hkStringPtr.h"
#include "hkpLinkedCollidable.h"
struct hkpWorldObject__VFTable;
struct hkpWorld_938ebb10;
struct hkpWorldObject {
    hkpWorldObject__VFTable* vftable_hkpWorldObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpWorld_938ebb10* m_world_10;
    unsigned long long m_userData_18;
    hkpLinkedCollidable m_collidable_20;
    hkMultiThreadCheck m_multiThreadCheck_A0;
    char _pad_AC[4];
    hkStringPtr m_name_B0;
    hkArray_hkpProperty_hkContainerHeapAllocator m_properties_B8;
    void* m_treeData_C8;
};
static_assert(sizeof(hkpWorldObject) == 208, "hkpWorldObject layout differs from the PDB");
