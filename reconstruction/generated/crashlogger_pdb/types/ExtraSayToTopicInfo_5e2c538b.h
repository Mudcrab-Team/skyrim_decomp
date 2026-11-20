// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSayToTopicInfo; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSSoundHandle.h"
struct BGSDialogueBranch_10ee3dbc;
struct DialogueItem;
struct TESTopic_3cb1295e;
struct ExtraSayToTopicInfo_5e2c538b {
    BSExtraData_4ca6af76 _base;
    TESTopic_3cb1295e* topic;
    bool voicePaused;
    unsigned char pad19;
    unsigned short pad1A;
    float subtitleSpeechDelay;
    BGSDialogueBranch_10ee3dbc* exclusiveBranch;
    BSSoundHandle sound;
    unsigned int pad34;
    DialogueItem* item;
};
static_assert(sizeof(ExtraSayToTopicInfo_5e2c538b) == 64, "ExtraSayToTopicInfo_5e2c538b layout differs from the PDB");
