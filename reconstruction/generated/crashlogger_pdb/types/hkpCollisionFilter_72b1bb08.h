// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionFilter; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "hkEnum_hkpCollisionFilter__hkpFilterType_uint32.h"
struct hkpCollidableCollidableFilter__VFTable;
struct hkpCollisionFilter__VFTable;
struct hkpRayCollidableFilter__VFTable;
struct hkpRayShapeCollectionFilter__VFTable;
struct hkpShapeCollectionFilter__VFTable;
struct hkpCollisionFilter_72b1bb08 {
    hkpCollisionFilter__VFTable* vftable_hkpCollisionFilter_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpCollidableCollidableFilter__VFTable* vftable_hkpCollidableCollidableFilter_10;
    hkpShapeCollectionFilter__VFTable* vftable_hkpShapeCollectionFilter_18;
    hkpRayShapeCollectionFilter__VFTable* vftable_hkpRayShapeCollectionFilter_20;
    hkpRayCollidableFilter__VFTable* vftable_hkpRayCollidableFilter_28;
    unsigned int m_prepad_30[2];
    hkEnum_hkpCollisionFilter__hkpFilterType_uint32 m_type_38;
    unsigned int m_postpad_3C[3];
};
static_assert(sizeof(hkpCollisionFilter_72b1bb08) == 72, "hkpCollisionFilter_72b1bb08 layout differs from the PDB");
