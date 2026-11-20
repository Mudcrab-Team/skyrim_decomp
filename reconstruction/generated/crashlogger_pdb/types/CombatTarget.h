// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatTarget; size 0xa8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "BGSWorldLocation.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "EnumSet_RE__CombatTarget__Flags_unsigned_short_4f68d756.h"
struct CombatTarget {
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
    EnumSet_RE__CombatTarget__Flags_unsigned_short_4f68d756 flags;
};
static_assert(sizeof(CombatTarget) == 168, "CombatTarget layout differs from the PDB");
