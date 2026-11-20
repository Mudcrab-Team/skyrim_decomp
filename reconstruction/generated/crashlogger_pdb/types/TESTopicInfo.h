// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESTopicInfo; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESCondition.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESTopicInfo__Data.h"
struct TESTopic;
struct TESTopicInfo__VFTable;
struct TESTopicInfo {
    TESTopicInfo__VFTable* vftable_TESTopicInfo_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESTopic* ParentTopic_20;
    TESTopicInfo* DataInfo_28;
    TESCondition Conditions_30;
    unsigned short IndexInParentInfoArray_38;
    bool SaidOnce_3A;
    char FavorLevel_3B;
    TESTopicInfo__Data TopicData_3C;
    unsigned int FileOffset_40;
    char _pad_44[4];
    unsigned char undefined_48[8];
};
static_assert(sizeof(TESTopicInfo) == 80, "TESTopicInfo layout differs from the PDB");
