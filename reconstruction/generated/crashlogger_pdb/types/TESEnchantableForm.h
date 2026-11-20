// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEnchantableForm; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct EnchantmentItem;
struct TESEnchantableForm__VFTable;
struct TESEnchantableForm {
    TESEnchantableForm__VFTable* vftable_TESEnchantableForm_0;
    EnchantmentItem* FormEnchanting_8;
    unsigned short castingType;  // CastingType in the PDB is wider than this slot
    unsigned short amountofEnchantment;
    unsigned int pad14;
};
static_assert(sizeof(TESEnchantableForm) == 24, "TESEnchantableForm layout differs from the PDB");
