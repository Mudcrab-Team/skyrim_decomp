// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionEvent; size 0x20
#pragma once

struct hkpRigidBody;
struct hkpSimpleConstraintContactMgr;
struct hkpCollisionEvent {
    int m_source_0;
    char _pad_4[4];
    hkpRigidBody* m_bodies_8[2];
    hkpSimpleConstraintContactMgr* m_contactMgr_18;
};
static_assert(sizeof(hkpCollisionEvent) == 32, "hkpCollisionEvent layout differs from the PDB");
