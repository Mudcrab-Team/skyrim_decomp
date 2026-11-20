// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CannotCastReason
#pragma once
enum class CannotCastReason : int {
    kOK = 0,
    kMagicka = 1,
    kPowerUsed = 2,
    kRangedUnderWater = 3,
    kMultipleCast = 4,
    kItemCharge = 5,
    kCastWhileShouting = 6,
    kShoutWhileCasting = 7,
    kShoutWhileRecovering = 8,
    kCustomReasonNoStart = 100,
};
