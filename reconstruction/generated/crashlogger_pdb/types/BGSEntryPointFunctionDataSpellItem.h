// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointFunctionDataSpellItem; size 0x10
#pragma once

#include "BGSEntryPointFunctionData.h"
struct SpellItem_847bf892;
struct BGSEntryPointFunctionDataSpellItem {
    BGSEntryPointFunctionData _base;
    SpellItem_847bf892* spell;
};
static_assert(sizeof(BGSEntryPointFunctionDataSpellItem) == 16, "BGSEntryPointFunctionDataSpellItem layout differs from the PDB");
