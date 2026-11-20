// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEntryPointFunctionDataActivateChoice; size 0x28
#pragma once

#include "BGSEntryPointFunctionData.h"
#include "BSFixedString_char_83b572b4.h"
struct BGSPerk_dfc65d7f;
struct SpellItem_847bf892;
struct BGSEntryPointFunctionDataActivateChoice {
    BGSEntryPointFunctionData _base;
    BSFixedString_char_83b572b4 label;
    BGSPerk_dfc65d7f* perk;
    SpellItem_847bf892* appliedSpell;
    unsigned short flags;  // Flag in the PDB is wider than this slot
    unsigned short id;
    unsigned int pad24;
};
static_assert(sizeof(BGSEntryPointFunctionDataActivateChoice) == 40, "BGSEntryPointFunctionDataActivateChoice layout differs from the PDB");
