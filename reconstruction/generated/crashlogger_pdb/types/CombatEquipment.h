// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatEquipment; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__NiPointer_RE__CombatInventoryItem_8d7c6d5d_e0a77acd.h"
struct CombatEquipment {
    BSTArray_RE__NiPointer_RE__CombatInventoryItem_8d7c6d5d_e0a77acd items;
    unsigned int slot;
    float maxRange;
    float optimalRange;
    float minRange;
    float score;
    unsigned char undefined_2c[4];
};
static_assert(sizeof(CombatEquipment) == 48, "CombatEquipment layout differs from the PDB");
