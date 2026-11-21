// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GeneralFlag
#pragma once
enum class GeneralFlag : int {
    kNone = 0,
    kOffersServices = 1,
    kMustComplete = 4,
    kMaintainSpeedAtGoal = 8,
    kUnlocksDoorsAtPackageStart = 64,
    kUnlocksDoorsAtPackageEnd = 128,
    kContinueIfPCNear = 512,
    kOncePerDay = 1024,
    kCreated = 2048,
    kPreferredSpeed = 8192,
    kAlwaysSneak = 131072,
    kAllowSwimming = 262144,
    kIgnoreCombat = 1048576,
    kWeaponsUnequipped = 2097152,
    kWeaponDrawn = 8388608,
    kNoCombatAlert = 134217728,
    kWearSleepOutfit = 536870912,
};
