// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSKeywordForm; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct BGSKeyword;
struct BGSKeywordForm_9c083c55 {
    BaseFormComponent _base;
    BGSKeyword** keywords;
    unsigned int numKeywords;
    unsigned int pad14;
};
static_assert(sizeof(BGSKeywordForm_9c083c55) == 24, "BGSKeywordForm_9c083c55 layout differs from the PDB");
