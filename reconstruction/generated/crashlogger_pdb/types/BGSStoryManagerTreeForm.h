// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerTreeForm; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESForm.h"
struct BGSStoryManagerTreeForm {
    TESForm _base;
    unsigned int lastVisitorID;
    unsigned int pad24;
};
static_assert(sizeof(BGSStoryManagerTreeForm) == 40, "BGSStoryManagerTreeForm layout differs from the PDB");
