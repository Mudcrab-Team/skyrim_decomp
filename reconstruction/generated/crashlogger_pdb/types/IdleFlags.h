// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IdleFlags
#pragma once
enum class IdleFlags : int {
    kNone = 0,
    kPickSequence = 1,
    kOldPickConditions = 2,
    kDoOnce = 4,
    kLooseOnly = 8,
    kNoSandbox = 16,
};
