// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShape; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkpShapeType_uint32.h"
struct hkpShape__VFTable;
struct hkpShape {
    hkpShape__VFTable* vftable_hkpShape_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned long long m_userData_10;
    hkEnum_hkpShapeType_uint32 m_type_18;
    char _pad_1C[4];
};
static_assert(sizeof(hkpShape) == 32, "hkpShape layout differs from the PDB");
