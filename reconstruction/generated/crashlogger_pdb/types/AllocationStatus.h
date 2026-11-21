// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AllocationStatus
#pragma once
enum class AllocationStatus : int {
    kSuccess = 0,
    kFailed = 1,
    kOutOfMemory = 2,
};
