// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactPointAddedEvent; size 0x58
#pragma once

#include "hkEnum_hkpContactPointAddedEvent__Type_int32.h"
struct hkContactPoint_68092cba;
struct hkpCdBody_cce531ab;
struct hkpContactPointProperties;
struct hkpDynamicsContactMgr;
struct hkpEntity_b3bc9432;
struct hkpGskCache;
struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpContactPointAddedEvent {
    hkpCdBody_cce531ab* m_bodyA_0;
    hkpCdBody_cce531ab* m_bodyB_8;
    hkEnum_hkpContactPointAddedEvent__Type_int32 m_type_10;
    char _pad_14[4];
    hkpEntity_b3bc9432* m_callbackFiredFrom_18;
    hkContactPoint_68092cba* m_contactPoint_20;
    hkpGskCache* m_gskCache_28;
    hkpContactPointProperties* m_contactPointProperties_30;
    float m_projectedVelocity_38;
    int m_status_3C;
    hkpDynamicsContactMgr* m_internalContactMgr_40;
    hkpProcessCollisionInput* m_collisionInput_48;
    hkpProcessCollisionOutput* m_collisionOutput_50;
};
static_assert(sizeof(hkpContactPointAddedEvent) == 88, "hkpContactPointAddedEvent layout differs from the PDB");
