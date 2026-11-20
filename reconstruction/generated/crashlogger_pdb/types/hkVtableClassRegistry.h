// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkVtableClassRegistry; size 0x20
#pragma once

#include "hkPointerMap_void__hkClass__hkContainerHeapAllocator.h"
struct hkVtableClassRegistry__VFTable;
struct hkVtableClassRegistry {
    hkVtableClassRegistry__VFTable* vftable_hkVtableClassRegistry_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkPointerMap_void__hkClass__hkContainerHeapAllocator m_map_10;
};
static_assert(sizeof(hkVtableClassRegistry) == 32, "hkVtableClassRegistry layout differs from the PDB");
