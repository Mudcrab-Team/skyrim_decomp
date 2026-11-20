// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactPointEvent; size 0x68
#pragma once

#include "hkBool.h"
struct hkContactPoint_68092cba;
struct hkpContactPointProperties;
struct hkpRigidBody;
struct hkpSimpleConstraintContactMgr;
struct hkpVelocityAccumulator;
struct hkpContactPointEvent {
    int m_source_0;
    char _pad_4[4];
    hkpRigidBody* m_bodies_8[2];
    hkpSimpleConstraintContactMgr* m_contactMgr_18;
    int m_type_20;
    char _pad_24[4];
    hkContactPoint_68092cba* m_contactPoint_28;
    hkpContactPointProperties* m_contactPointProperties_30;
    hkBool m_firingCallbacksForFullManifold_38;
    hkBool m_firstCallbackForFullManifold_39;
    hkBool m_lastCallbackForFullManifold_3A;
    char _pad_3B[5];
    float* m_separatingVelocity_40;
    float* m_rotateNormal_48;
    unsigned int* m_shapeKeyStorage_50;
    hkpVelocityAccumulator* m_accumulators_58[2];
};
static_assert(sizeof(hkpContactPointEvent) == 104, "hkpContactPointEvent layout differs from the PDB");
