// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CallResult
#pragma once
enum class CallResult : int {
    kCompleted = 0,
    kSetupForVM = 1,
    kInProgress = 2,
    kFailedRetry = 3,
    kFailedAbort = 4,
};
