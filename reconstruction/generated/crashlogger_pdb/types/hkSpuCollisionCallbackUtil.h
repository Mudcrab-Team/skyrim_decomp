// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSpuCollisionCallbackUtil; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkSpuCollisionCallbackUtil__Event.h"
struct hkReferencedObject__VFTable;
struct hkSpuCollisionCallbackUtil {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned int m_capacity_10;
    char _pad_14[4];
    void* m_nextFreeEvent_18;
    hkSpuCollisionCallbackUtil__Event m_events_20[1];
};
static_assert(sizeof(hkSpuCollisionCallbackUtil) == 64, "hkSpuCollisionCallbackUtil layout differs from the PDB");
