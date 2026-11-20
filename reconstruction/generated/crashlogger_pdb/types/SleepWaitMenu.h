// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SleepWaitMenu; size 0x58
#pragma once

#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct SleepWaitMenu {
    IMenu_09c1ffe2 _base;
    float timer;
    unsigned int pad34;
    GFxValue root;
    bool isSleeping;
    bool isActive;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(SleepWaitMenu) == 88, "SleepWaitMenu layout differs from the PDB");
