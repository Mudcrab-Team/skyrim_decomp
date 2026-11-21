// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSIdleCollection; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct TESIdleForm_2b3518b0;
struct BGSIdleCollection_ffcdd2aa {
    BaseFormComponent _base;
    unsigned char idleFlags;  // IdleFlags in the PDB is wider than this slot
    unsigned char idleCount;
    unsigned short pad0A;
    unsigned int pad0C;
    TESIdleForm_2b3518b0** idles;
    float timerCheckForIdle;
    unsigned int pad1C;
};
static_assert(sizeof(BGSIdleCollection_ffcdd2aa) == 32, "BGSIdleCollection_ffcdd2aa layout differs from the PDB");
