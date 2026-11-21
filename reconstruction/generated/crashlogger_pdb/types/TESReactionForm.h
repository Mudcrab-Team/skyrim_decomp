// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESReactionForm; size 0x20
#pragma once

#include "BSSimpleList_RE__GROUP_REACTION_44524c0c.h"
#include "BaseFormComponent.h"
struct TESReactionForm {
    BaseFormComponent _base;
    BSSimpleList_RE__GROUP_REACTION_44524c0c reactions;
    unsigned char groupFormType;  // FormType in the PDB is wider than this slot
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(TESReactionForm) == 32, "TESReactionForm layout differs from the PDB");
