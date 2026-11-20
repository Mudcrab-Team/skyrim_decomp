// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItemPotion; size 0x50
#pragma once

#include "CombatInventoryItemMagic.h"
struct CombatInventoryItemPotion {
    CombatInventoryItemMagic _base;
};
static_assert(sizeof(CombatInventoryItemPotion) == 80, "CombatInventoryItemPotion layout differs from the PDB");
