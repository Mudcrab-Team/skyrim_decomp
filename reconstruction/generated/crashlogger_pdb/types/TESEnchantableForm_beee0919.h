// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEnchantableForm; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct EnchantmentItem_57a0edce;
struct TESEnchantableForm_beee0919 {
    BaseFormComponent _base;
    EnchantmentItem_57a0edce* formEnchanting;
    unsigned short castingType;  // CastingType in the PDB is wider than this slot
    unsigned short amountofEnchantment;
    unsigned int pad14;
};
static_assert(sizeof(TESEnchantableForm_beee0919) == 24, "TESEnchantableForm_beee0919 layout differs from the PDB");
