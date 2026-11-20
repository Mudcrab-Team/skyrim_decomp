// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItemStaff; size 0x50
#pragma once

#include "CombatInventoryItemMagic.h"
struct CombatInventoryItemStaff {
    CombatInventoryItemMagic _base;
};
static_assert(sizeof(CombatInventoryItemStaff) == 80, "CombatInventoryItemStaff layout differs from the PDB");
