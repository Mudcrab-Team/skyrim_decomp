// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AttackFlag
#pragma once
enum class AttackFlag : int {
    kOverrideData = -2147483648,
    kNone = 0,
    kIgnoreWeapon = 1,
    kBashAttack = 2,
    kPowerAttack = 4,
    kChargeAttack = 8,
    kRotatingAttack = 16,
    kContinuousAttack = 32,
};
