// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDialogueBranch; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_d5bcd2af.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSDialogueBranch__VFTable;
struct TESQuest;
struct TESTopic;
struct BGSDialogueBranch {
    BGSDialogueBranch__VFTable* vftable_BGSDialogueBranch_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    Flag_d5bcd2af flags;
    unsigned int pad24;
    TESQuest* Quest_28;
    TESTopic* StartingTopic_30;
    unsigned char type_raw[4];
    unsigned int pad3C;
};
static_assert(sizeof(BGSDialogueBranch) == 64, "BGSDialogueBranch layout differs from the PDB");
