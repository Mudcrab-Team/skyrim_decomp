// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellItem::SpellFlag
#pragma once
enum class SpellItem__SpellFlag : int {
    SpellItem__SpellFlags_None = 0,
    SpellItem__SpellFlags_CostOverride = 1,
    SpellItem__SpellFlags_FoodItem = 2,
    SpellItem__SpellFlags_ExtendDuration = 8,
    SpellItem__SpellFlags_PCStartSpell = 131072,
    SpellItem__SpellFlags_InstantCast = 262144,
    SpellItem__SpellFlags_IgnoreLOSCheck = 524288,
    SpellItem__SpellFlags_IgnoreResistance = 1048576,
    SpellItem__SpellFlags_NoAbsorb = 2097152,
    SpellItem__SpellFlags_NoDualCastMods = 8388608,
};
