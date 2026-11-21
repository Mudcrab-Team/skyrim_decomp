// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatPath; size 0x38
#pragma once

#include "AITimer.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "CombatObject_2faf992b.h"
#include "STATE.h"
struct CombatPath {
    CombatObject_2faf992b _base;
    BSPointerHandle_RE__Actor_1a35f4b9 actorhandle;
    STATE state;
    STATE last_state;
    unsigned int speed;
    AITimer PathRetryTimer;
    AITimer timer;
    void* speedcontroller;
};
static_assert(sizeof(CombatPath) == 56, "CombatPath layout differs from the PDB");
