// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EquipmentFlag
#pragma once
enum class EquipmentFlag : int {
    kNone = 0,
    kHandToHandMelee = 1,
    kOneHandSword = 2,
    kOneHandDagger = 4,
    kOneHandAxe = 8,
    kOneHandMace = 16,
    kTwoHandSword = 32,
    kTwoHandAxe = 64,
    kBow = 128,
    kStaff = 256,
    kSpell = 512,
    kShield = 1024,
    kTorch = 2048,
    kCrossbow = 4096,
};
