// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LOCK_LEVEL
#pragma once
enum class LOCK_LEVEL : int {
    kUnlocked = -1,
    kVeryEasy = 0,
    kEasy = 1,
    kAverage = 2,
    kHard = 3,
    kVeryHard = 4,
    kRequiresKey = 5,
};
