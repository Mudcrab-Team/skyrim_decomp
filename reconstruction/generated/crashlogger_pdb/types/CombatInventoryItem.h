// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItem; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CombatInventoryItemSlot.h"
#include "CombatObject.h"
struct TESForm_4074aa87;
struct CombatInventoryItem {
    CombatObject _base;
    TESForm_4074aa87* item;
    float itemScore;
    unsigned int unk1C;
    CombatInventoryItemSlot itemSlot;
};
static_assert(sizeof(CombatInventoryItem) == 48, "CombatInventoryItem layout differs from the PDB");
