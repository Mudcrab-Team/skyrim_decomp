// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactProcessEvent; size 0x828
#pragma once

struct hkpCollidable;
struct hkpContactPointProperties;
struct hkpDynamicsContactMgr;
struct hkpEntity_b3bc9432;
struct hkpProcessCollisionData;
struct hkpContactProcessEvent {
    hkpCollidable* m_collidableA_0;
    hkpCollidable* m_collidableB_8;
    hkpEntity_b3bc9432* m_callbackFiredFrom_10;
    hkpProcessCollisionData* m_collisionData_18;
    hkpContactPointProperties* m_contactPointProperties_20[256];
    hkpDynamicsContactMgr* m_internalContactMgr_820;
};
static_assert(sizeof(hkpContactProcessEvent) == 2088, "hkpContactProcessEvent layout differs from the PDB");
