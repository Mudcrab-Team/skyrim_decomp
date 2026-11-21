// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItemScroll; size 0x50
#pragma once

#include "CombatInventoryItemMagic.h"
struct CombatInventoryItemScroll {
    CombatInventoryItemMagic _base;
};
static_assert(sizeof(CombatInventoryItemScroll) == 80, "CombatInventoryItemScroll layout differs from the PDB");
