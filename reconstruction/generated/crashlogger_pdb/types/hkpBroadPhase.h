// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhase; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Capabilities.h"
#include "hkMultiThreadCheck.h"
struct hkCriticalSection;
struct hkpBroadPhase__VFTable;
struct hkpBroadPhase {
    hkpBroadPhase__VFTable* vftable_hkpBroadPhase_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned short type;  // BroadPhaseType in the PDB is wider than this slot
    unsigned short size;
    Capabilities caps;
    hkMultiThreadCheck m_multiThreadCheck_18;
    unsigned int pad24;
    hkCriticalSection* m_criticalSection_28;
};
static_assert(sizeof(hkpBroadPhase) == 48, "hkpBroadPhase layout differs from the PDB");
