// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPerk; size 0x80
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSPerkEntry_3823d5af.h"
#include "TESCondition_4d3cdc88.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
struct BGSPerk_dfc65d7f {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESDescription _base_TESDescription;
    TESIcon_05686730 _base_TESIcon;
    unsigned char data_raw[5];
    unsigned char pad55;
    unsigned short pad56;
    TESCondition_4d3cdc88 perkConditions;
    BSTArray_RE__BGSPerkEntry_3823d5af perkEntries;
    BGSPerk_dfc65d7f* nextPerk;
};
static_assert(sizeof(BGSPerk_dfc65d7f) == 128, "BGSPerk_dfc65d7f layout differs from the PDB");
