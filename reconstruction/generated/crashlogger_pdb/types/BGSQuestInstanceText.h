// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSQuestInstanceText; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSQuestInstanceText__GlobalValueData_5c97e055_2ae87c8a.h"
#include "BSTArray_RE__BGSQuestInstanceText__StringData_08e65711_bc879e09.h"
struct BGSQuestInstanceText {
    unsigned int id;
    unsigned int pad04;
    BSTArray_RE__BGSQuestInstanceText__StringData_08e65711_bc879e09 stringData;
    BSTArray_RE__BGSQuestInstanceText__GlobalValueData_5c97e055_2ae87c8a valueData;
    unsigned short journalStage;
    unsigned char journalStageItem;
    unsigned char pad3B;
    unsigned int pad3C;
};
static_assert(sizeof(BGSQuestInstanceText) == 64, "BGSQuestInstanceText layout differs from the PDB");
