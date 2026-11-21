// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTriangleShape; size 0x30
#pragma once

#include "hkEnum_hkpShapeType_uint32.h"
struct hkpShape__VFTable;
struct hkpTriangleShape__VFTable;
struct hkpTriangleShape {
    hkpTriangleShape__VFTable* vftable_hkpTriangleShape_0;
    hkpShape__VFTable* vftable_hkpShape_8;
    unsigned short m_memSizeAndFlags_10;
    short m_referenceCount_12;
    char _pad_14[4];
    unsigned long long m_userData_18;
    hkEnum_hkpShapeType_uint32 m_type_20;
    char _pad_24[4];
    float m_radius_28;
    char _pad_2C[4];
};
static_assert(sizeof(hkpTriangleShape) == 48, "hkpTriangleShape layout differs from the PDB");
