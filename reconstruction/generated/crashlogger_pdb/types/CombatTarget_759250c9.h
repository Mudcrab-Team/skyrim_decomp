// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTarget; size 0xa8
// one of 2 different PDB types sharing this name
#pragma once

#include "AITimeStamp.h"
#include "BGSWorldLocation.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
struct CombatTarget_759250c9 {
    BSPointerHandle_RE__Actor_1a35f4b9 targetHandle;
    int detectLevel;
    float stealthPoints;
    float unk0C;
    BGSWorldLocation lastKnownLoc;
    BGSWorldLocation unk28;
    BGSWorldLocation unk40;
    BGSWorldLocation searchLoc;
    BGSWorldLocation unk70;
    AITimeStamp unk88;
    AITimeStamp unk8C;
    AITimeStamp lastKnownTimeStamp;
    AITimeStamp unk94;
    AITimeStamp unk98;
    AITimeStamp unk9C;
    BSPointerHandle_RE__Actor_1a35f4b9 attackedMember;
    unsigned short attackerCount;
    unsigned short flags;  // Flags in the PDB is wider than this slot
};
static_assert(sizeof(CombatTarget_759250c9) == 168, "CombatTarget_759250c9 layout differs from the PDB");
