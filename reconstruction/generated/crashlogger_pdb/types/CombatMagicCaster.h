// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMagicCaster; size 0x20
#pragma once

#include "CombatObject_2faf992b.h"
#include "NiPointer_RE__CombatInventoryItemMagic_011ed647.h"
struct MagicItem_34516af4;
struct CombatMagicCaster {
    CombatObject_2faf992b _base;
    NiPointer_RE__CombatInventoryItemMagic_011ed647 inventoryItem;
    MagicItem_34516af4* magicItem;
};
static_assert(sizeof(CombatMagicCaster) == 32, "CombatMagicCaster layout differs from the PDB");
