// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBvTreeShape; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkpBvTreeShape__BvTreeType_uint8.h"
#include "hkEnum_hkpShapeType_uint32.h"
struct hkpBvTreeShape__VFTable;
struct hkpBvTreeShape {
    hkpBvTreeShape__VFTable* vftable_hkpBvTreeShape_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned long long m_userData_10;
    hkEnum_hkpShapeType_uint32 m_type_18;
    char _pad_1C[4];
    hkEnum_hkpBvTreeShape__BvTreeType_uint8 m_bvTreeType_20;
    char _pad_21[7];
};
static_assert(sizeof(hkpBvTreeShape) == 40, "hkpBvTreeShape layout differs from the PDB");
