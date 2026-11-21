// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatEquippedItem; size 0x10
#pragma once

#include "NiPointer_RE__CombatInventoryItem_41fc5e39.h"
struct CombatEquippedItem {
    NiPointer_RE__CombatInventoryItem_41fc5e39 item;
    unsigned char equipTime_raw[8];
};
static_assert(sizeof(CombatEquippedItem) == 16, "CombatEquippedItem layout differs from the PDB");
