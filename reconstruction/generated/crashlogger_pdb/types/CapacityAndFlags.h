// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CapacityAndFlags
#pragma once
enum class CapacityAndFlags : int {
    kCapacityMask = 0,
    kFlagMask = 1,
    kNoDealloc = 2,
    kLocked = 3,
    kForceSigned = 4,
};
