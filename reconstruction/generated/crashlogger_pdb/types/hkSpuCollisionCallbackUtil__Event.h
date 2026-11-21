// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSpuCollisionCallbackUtil__Event; size 0x20
#pragma once

#include "hkEnum_hkSpuCollisionCallbackUtil__Event__EventType_uint16.h"
struct hkpDynamicsContactMgr;
struct hkpEntity_b3bc9432;
struct hkSpuCollisionCallbackUtil__Event {
    unsigned short m_size_0;
    hkEnum_hkSpuCollisionCallbackUtil__Event__EventType_uint16 m_type_2;
    char _pad_4[4];
    hkpEntity_b3bc9432* m_entityA_8;
    hkpEntity_b3bc9432* m_entityB_10;
    hkpDynamicsContactMgr* m_contactMgr_18;
};
static_assert(sizeof(hkSpuCollisionCallbackUtil__Event) == 32, "hkSpuCollisionCallbackUtil__Event layout differs from the PDB");
