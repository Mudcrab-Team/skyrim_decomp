// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatManager; size 0x68
#pragma once

#include "AITimeStamp.h"
#include "AITimer.h"
#include "BSReadWriteLock.h"
#include "NiTPrimitiveArray_RE__CombatGroup_4fab0b29.h"
struct CombatThreatMap;
struct RE__BSTScatterTable_RE__BSCRC32_RE__BSPointerHandle_RE__Actor_std__equal_to_RE__BSPoint_a5a5a16c;
struct CombatManager {
    NiTPrimitiveArray_RE__CombatGroup_4fab0b29 combatGroups;
    BSReadWriteLock lock;
    RE__BSTScatterTable_RE__BSCRC32_RE__BSPointerHandle_RE__Actor_std__equal_to_RE__BSPoint_a5a5a16c* localActorTargetingMap;
    CombatThreatMap* combatThreatMap;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned long long unk40;
    AITimeStamp musicStartedTimeStamp;
    AITimer musicStopTimer;
    AITimer musicUpdateTimer;
    unsigned int combatCount;
    unsigned int groupCount;
    unsigned int unk64;
};
static_assert(sizeof(CombatManager) == 104, "CombatManager layout differs from the PDB");
