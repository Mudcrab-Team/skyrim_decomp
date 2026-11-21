// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItem; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "CombatInventoryItemSlot.h"
#include "CombatObject_2faf992b.h"
struct TESForm;
struct CombatInventoryItem_22936e3f {
    CombatObject_2faf992b _base;
    TESForm* item;
    float itemScore;
    unsigned int unk1C;
    CombatInventoryItemSlot itemSlot;
};
static_assert(sizeof(CombatInventoryItem_22936e3f) == 48, "CombatInventoryItem_22936e3f layout differs from the PDB");
