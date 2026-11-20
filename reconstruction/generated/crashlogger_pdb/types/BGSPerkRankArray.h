// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerkRankArray; size 0x18
#pragma once

#include "BaseFormComponent.h"
struct PerkRankData;
struct BGSPerkRankArray {
    BaseFormComponent _base;
    PerkRankData* perks;
    unsigned int perkCount;
    unsigned int pad14;
};
static_assert(sizeof(BGSPerkRankArray) == 24, "BGSPerkRankArray layout differs from the PDB");
