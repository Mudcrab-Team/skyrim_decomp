// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSActionData; size 0x60
#pragma once

#include "ActionInput.h"
#include "ActionOutput.h"
struct BGSActionData {
    ActionInput _base;
    ActionOutput _base_ActionOutput;
    unsigned int flags;
    unsigned char undefined_5c[4];
};
static_assert(sizeof(BGSActionData) == 96, "BGSActionData layout differs from the PDB");
