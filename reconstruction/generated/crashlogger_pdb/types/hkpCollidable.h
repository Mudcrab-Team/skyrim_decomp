// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidable; size 0x70
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpTypedBroadPhaseHandle.h"
struct hkpShape;
#pragma pack(push, 2)
struct hkpCollidable {
    void* m_motion_10;
    hkpShape* m_shape_0;
    float m_allowedPenetrationDepth_68;
    unsigned char undefined_14[12];
    unsigned char ownerOffset;
    unsigned char forceCollideOntoPpu;
    unsigned short shapeSizeOnSpu;
    hkpTypedBroadPhaseHandle broadPhaseHandle;
    unsigned char undefined_30[28];
    unsigned short m_shapeSizeOnSpu_22;
    hkpTypedBroadPhaseHandle m_broadPhaseHandle_24;
    unsigned int m_shapeKey_8;
    char m_ownerOffset_20;
    char _pad_C[4];
    char _pad_6C[4];
    unsigned char undefined_67[1];
    float allowedPenetrationDepth;
    unsigned char undefined_6c[3];
    unsigned char m_forceCollideOntoPpu_21;
};
#pragma pack(pop)
static_assert(sizeof(hkpCollidable) == 112, "hkpCollidable layout differs from the PDB");
