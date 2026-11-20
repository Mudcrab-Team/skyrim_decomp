// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LowProcessFlags
#pragma once
enum class LowProcessFlags : int {
    kNone = 0,
    kTargetActivated = 1,
    kCurrentActionComplete = 2,
    kIsAggressor = 4,
    kAlert = 8,
    kFollower = 16,
    kPackageDoneOnce = 32,
    kPackageIdleDone = 64,
};
