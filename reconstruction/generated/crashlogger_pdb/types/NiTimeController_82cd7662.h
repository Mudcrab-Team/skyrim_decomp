// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTimeController; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiTimeController_8219d923.h"
struct NiObjectNET;
struct NiTimeController_82cd7662 {
    NiObject_de5bc370 _base;
    unsigned short flags;  // Flag in the PDB is wider than this slot
    unsigned short pad12;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    float startTime;
    float lastTime;
    float weightedLastTime;
    float scaledTime;
    unsigned int pad34;
    NiObjectNET* target;
    NiPointer_RE__NiTimeController_8219d923 next;
};
static_assert(sizeof(NiTimeController_82cd7662) == 72, "NiTimeController_82cd7662 layout differs from the PDB");
