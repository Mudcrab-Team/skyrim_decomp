// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction; size 0x100
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AITimeStamp.h"
#include "BSFixedString.h"
#include "BSSimpleList_TESFaction__RankData.h"
#include "BSSimpleList_TESReactionForm__Data.h"
#include "TESFaction__CrimeData.h"
#include "TESFaction__VendorData.h"
#include "TESFileContainer_70f0bdf4.h"
struct BSTHashMap_TESNPC__uint32;
struct TESFaction__VFTable;
struct TESFullName__VFTable;
struct TESReactionForm__VFTable;
struct TESFaction {
    TESFaction__VFTable* vftable_TESFaction_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    TESReactionForm__VFTable* vftable_TESReactionForm_30;
    BSSimpleList_TESReactionForm__Data Reactions_38;
    unsigned char GroupFormType_48;
    char _pad_49[7];
    BSTHashMap_TESNPC__uint32* CrimeGoldMap_50;
    unsigned int FactionFlags_58;
    char _pad_5C[4];
    TESFaction__CrimeData CrimeSettings_60;
    TESFaction__VendorData VendorSettings_A8;
    BSSimpleList_TESFaction__RankData RankSettings_E0;
    int MajorCrime_F0;
    int MinorCrime_F4;
    AITimeStamp ResistArrestTimeStamp_F8;
    float PcEnemyFlagTimeStamp_FC;
};
static_assert(sizeof(TESFaction) == 256, "TESFaction layout differs from the PDB");
