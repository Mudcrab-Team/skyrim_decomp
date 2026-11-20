// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FilterFlag
#pragma once
enum class FilterFlag : int {
    EnchantWeapon = 1,
    DisenchantWeapon = 2,
    EnchantArmor = 4,
    DisenchantArmor = 8,
    EffectWeapon = 16,
    EffectArmor = 32,
    SoulGem = 64,
};
