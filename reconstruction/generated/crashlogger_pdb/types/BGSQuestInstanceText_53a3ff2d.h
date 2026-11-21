// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSQuestInstanceText; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSQuestInstanceText__GlobalValueData_5c97e055.h"
#include "BSTArray_RE__BGSQuestInstanceText__StringData_08e65711.h"
struct BGSQuestInstanceText_53a3ff2d {
    unsigned int id;
    unsigned int pad04;
    BSTArray_RE__BGSQuestInstanceText__StringData_08e65711 stringData;
    BSTArray_RE__BGSQuestInstanceText__GlobalValueData_5c97e055 valueData;
    unsigned short journalStage;
    unsigned char journalStageItem;
    unsigned char pad3B;
    unsigned int pad3C;
};
static_assert(sizeof(BGSQuestInstanceText_53a3ff2d) == 64, "BGSQuestInstanceText_53a3ff2d layout differs from the PDB");
