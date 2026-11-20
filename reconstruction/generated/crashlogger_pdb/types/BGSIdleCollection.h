// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSIdleCollection; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent_9d659514.h"
struct TESIdleForm;
struct BGSIdleCollection {
    BaseFormComponent_9d659514 _base;
    unsigned char idleFlags;  // IdleFlags in the PDB is wider than this slot
    unsigned char idleCount;
    unsigned short pad0A;
    unsigned int pad0C;
    TESIdleForm** idles;
    float timerCheckForIdle;
    unsigned int pad1C;
};
static_assert(sizeof(BGSIdleCollection) == 32, "BGSIdleCollection layout differs from the PDB");
