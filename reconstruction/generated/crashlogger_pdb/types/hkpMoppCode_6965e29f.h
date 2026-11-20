// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMoppCode; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_uint8_hkContainerHeapAllocator.h"
#include "hkEnum_hkpMoppCode__BuildType_int8.h"
#include "hkpMoppCode__CodeInfo.h"
struct hkpMoppCode__VFTable;
struct hkpMoppCode_6965e29f {
    hkpMoppCode__VFTable* vftable_hkpMoppCode_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpMoppCode__CodeInfo m_info_10;
    hkArray_uint8_hkContainerHeapAllocator m_data_20;
    hkEnum_hkpMoppCode__BuildType_int8 m_buildType_30;
    char _pad_31[15];
};
static_assert(sizeof(hkpMoppCode_6965e29f) == 64, "hkpMoppCode_6965e29f layout differs from the PDB");
