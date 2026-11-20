// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDialogueBranch; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_a4a94b8a.h"
#include "TESForm.h"
struct TESQuest_fe66f8e1;
struct TESTopic_3cb1295e;
struct BGSDialogueBranch_10ee3dbc {
    TESForm _base;
    Flag_a4a94b8a flags;
    unsigned int pad24;
    TESQuest_fe66f8e1* quest;
    TESTopic_3cb1295e* startingTopic;
    unsigned char type_raw[4];
    unsigned int pad3C;
};
static_assert(sizeof(BGSDialogueBranch_10ee3dbc) == 64, "BGSDialogueBranch_10ee3dbc layout differs from the PDB");
