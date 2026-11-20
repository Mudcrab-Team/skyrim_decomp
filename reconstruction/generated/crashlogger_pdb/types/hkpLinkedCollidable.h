// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLinkedCollidable; size 0x80
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_hkpLinkedCollidable__CollisionEntry_hkContainerHeapAllocator.h"
#include "hkpCollidable__BoundingVolumeData.h"
#include "hkpTypedBroadPhaseHandle.h"
struct hkpCdBody_cce531ab;
struct hkpShape;
struct hkpLinkedCollidable {
    hkpShape* m_shape_0;
    unsigned int m_shapeKey_8;
    char _pad_C[4];
    void* m_motion_10;
    hkpCdBody_cce531ab* m_parent_18;
    char m_ownerOffset_20;
    unsigned char m_forceCollideOntoPpu_21;
    unsigned short m_shapeSizeOnSpu_22;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle_24;
    hkpCollidable__BoundingVolumeData m_boundingVolumeData_30;
    float m_allowedPenetrationDepth_68;
    char _pad_6C[4];
    hkArray_hkpLinkedCollidable__CollisionEntry_hkContainerHeapAllocator m_collisionEntries_70;
};
static_assert(sizeof(hkpLinkedCollidable) == 128, "hkpLinkedCollidable layout differs from the PDB");
