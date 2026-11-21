// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSKeywordForm; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent_9d659514.h"
struct BGSKeyword_f67121b2;
struct BGSKeywordForm {
    BaseFormComponent_9d659514 _base;
    BGSKeyword_f67121b2** keywords;
    unsigned int numKeywords;
    unsigned int pad14;
};
static_assert(sizeof(BGSKeywordForm) == 24, "BGSKeywordForm layout differs from the PDB");
