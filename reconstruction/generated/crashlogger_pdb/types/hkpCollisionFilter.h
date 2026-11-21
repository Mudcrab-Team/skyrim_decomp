// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionFilter; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkReferencedObject.h"
#include "hkpCollidableCollidableFilter.h"
#include "hkpFilterType.h"
#include "hkpRayCollidableFilter_f6618674.h"
#include "hkpRayShapeCollectionFilter.h"
#include "hkpShapeCollectionFilter_a2db964b.h"
struct hkpCollisionFilter {
    hkReferencedObject _base;
    hkpCollidableCollidableFilter _base_hkpCollidableCollidableFilter;
    hkpShapeCollectionFilter_a2db964b _base_hkpShapeCollectionFilter;
    hkpRayShapeCollectionFilter _base_hkpRayShapeCollectionFilter;
    hkpRayCollidableFilter_f6618674 _base_hkpRayCollidableFilter;
    unsigned int pad30;
    unsigned int pad34;
    hkpFilterType type;
    unsigned int pad3C;
    unsigned int pad40;
    unsigned int pad44;
};
static_assert(sizeof(hkpCollisionFilter) == 72, "hkpCollisionFilter layout differs from the PDB");
