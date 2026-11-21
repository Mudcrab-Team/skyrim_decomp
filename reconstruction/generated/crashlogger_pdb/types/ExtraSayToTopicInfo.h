// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSayToTopicInfo; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSoundHandle.h"
struct BGSDialogueBranch;
struct BSExtraData;
struct DialogueItem_6f899a07;
struct ExtraSayToTopicInfo__VFTable;
struct TESTopic;
struct ExtraSayToTopicInfo {
    ExtraSayToTopicInfo__VFTable* vftable_ExtraSayToTopicInfo_0;
    BSExtraData* Next_8;
    TESTopic* Topic_10;
    bool voicePaused;
    unsigned char pad19;
    unsigned short pad1A;
    float SubtitleSpeechDelay_1C;
    BGSDialogueBranch* ExclusiveBranch_20;
    BSSoundHandle sound;
    unsigned int pad34;
    DialogueItem_6f899a07* Item_38;
};
static_assert(sizeof(ExtraSayToTopicInfo) == 64, "ExtraSayToTopicInfo layout differs from the PDB");
