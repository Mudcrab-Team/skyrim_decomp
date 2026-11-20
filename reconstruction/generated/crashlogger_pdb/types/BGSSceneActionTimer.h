// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneActionTimer; size 0x30
#pragma once

#include "BGSSceneAction.h"
struct BGSSceneActionTimer {
    BGSSceneAction _base;
    float timerSeconds;
    unsigned int unk24;
    unsigned long long unk28;
};
static_assert(sizeof(BGSSceneActionTimer) == 48, "BGSSceneActionTimer layout differs from the PDB");
