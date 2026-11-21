// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItemSlot; size 0x10
#pragma once

struct BGSEquipSlot;
struct CombatInventoryItemSlot {
    BGSEquipSlot* equipSlot;
    unsigned int slot;
    unsigned char undefined_c[4];
};
static_assert(sizeof(CombatInventoryItemSlot) == 16, "CombatInventoryItemSlot layout differs from the PDB");
