// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerk; size 0x80
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSPerkEntry_3823d5af_c1153e62.h"
#include "PerkData.h"
#include "TESCondition.h"
#include "TESDescription_99869432.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
#include "TESIcon.h"
struct BGSPerk {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESDescription_99869432 _base_TESDescription;
    TESIcon _base_TESIcon;
    PerkData data;
    unsigned char pad55;
    unsigned short pad56;
    TESCondition perkConditions;
    BSTArray_RE__BGSPerkEntry_3823d5af_c1153e62 perkEntries;
    BGSPerk* nextPerk;
};
static_assert(sizeof(BGSPerk) == 128, "BGSPerk layout differs from the PDB");
