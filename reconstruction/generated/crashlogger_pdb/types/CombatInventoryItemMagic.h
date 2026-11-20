// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatInventoryItemMagic; size 0x50
#pragma once

#include "CombatInventoryItem_22936e3f.h"
struct Effect;
struct CombatInventoryItemMagic {
    CombatInventoryItem_22936e3f _base;
    float minRange;
    float maxRange;
    float tacticalDuration;
    float power;
    float currentAV;
    unsigned char undefined_44[4];
    Effect* effect;
};
static_assert(sizeof(CombatInventoryItemMagic) == 80, "CombatInventoryItemMagic layout differs from the PDB");
