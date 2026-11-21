// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactPointRemovedEvent; size 0x38
#pragma once

struct hkpConstraintOwner;
struct hkpContactPointProperties;
struct hkpDynamicsContactMgr;
struct hkpEntity_b3bc9432;
struct hkpContactPointRemovedEvent {
    unsigned short m_contactPointId_0;
    char _pad_2[6];
    hkpContactPointProperties* m_contactPointProperties_8;
    hkpEntity_b3bc9432* m_entityA_10;
    hkpEntity_b3bc9432* m_entityB_18;
    hkpEntity_b3bc9432* m_callbackFiredFrom_20;
    hkpDynamicsContactMgr* m_internalContactMgr_28;
    hkpConstraintOwner* m_constraintOwner_30;
};
static_assert(sizeof(hkpContactPointRemovedEvent) == 56, "hkpContactPointRemovedEvent layout differs from the PDB");
