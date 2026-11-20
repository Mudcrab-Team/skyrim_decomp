// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAction; size 0x30
#pragma once

#include "BGSKeyword.h"
struct BGSAction {
    BGSKeyword _base;
    unsigned int index;
    unsigned int pad2C;
};
static_assert(sizeof(BGSAction) == 48, "BGSAction layout differs from the PDB");
