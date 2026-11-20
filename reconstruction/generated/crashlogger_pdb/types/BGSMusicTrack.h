// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicTrack; size 0x20
#pragma once

#include "BSIMusicTrack.h"
#include "TESCondition_4d3cdc88.h"
struct BGSMusicTrack {
    BSIMusicTrack _base;
    TESCondition_4d3cdc88 conditions;
    unsigned long long unk18;
};
static_assert(sizeof(BGSMusicTrack) == 32, "BGSMusicTrack layout differs from the PDB");
