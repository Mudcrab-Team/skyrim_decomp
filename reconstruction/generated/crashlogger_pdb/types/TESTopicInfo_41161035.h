// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESTopicInfo; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
#include "TOPIC_INFO_DATA.h"
struct TESTopic_3cb1295e;
struct TESTopicInfo_41161035 {
    TESForm _base;
    TESTopic_3cb1295e* parentTopic;
    TESTopicInfo_41161035* dataInfo;
    TESCondition_4d3cdc88 objConditions;
    unsigned short infoIndex;
    bool saidOnce;
    unsigned char favorLevel;  // FavorLevel in the PDB is wider than this slot
    TOPIC_INFO_DATA data;
    unsigned int fileOffset;
    unsigned int pad44;
};
static_assert(sizeof(TESTopicInfo_41161035) == 72, "TESTopicInfo_41161035 layout differs from the PDB");
