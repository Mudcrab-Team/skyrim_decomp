// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Flag2
#pragma once
enum class Flag2 : int {
    kNone = 0,
    kPlayerOnly = 1,
    kNPCsUseAmmo = 2,
    kNoJamAfterReload = 4,
    kAllowMountedCombat = 16,
    kRangeFixed = 32,
    kNotUsedInNormalCombat = 64,
    kOverridesConditionDamage = 128,
    kDontUse3rdPersonISAnim = 256,
    kBurstShot = 512,
    kRumbleAlternate = 1024,
    kLongBursts = 2048,
    kNonHostile = 4096,
    kBoundWeapon = 8192,
};
