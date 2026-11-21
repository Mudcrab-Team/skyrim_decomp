// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhase; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "Capabilities.h"
#include "hkMultiThreadCheck_64f82694.h"
#include "hkReferencedObject.h"
struct hkCriticalSection_342cc62e;
struct hkpBroadPhase_ceb45477 {
    hkReferencedObject _base;
    unsigned short type;  // BroadPhaseType in the PDB is wider than this slot
    unsigned short size;
    Capabilities caps;
    hkMultiThreadCheck_64f82694 multiThreadCheck;
    unsigned int pad24;
    hkCriticalSection_342cc62e* criticalSection;
};
static_assert(sizeof(hkpBroadPhase_ceb45477) == 48, "hkpBroadPhase_ceb45477 layout differs from the PDB");
