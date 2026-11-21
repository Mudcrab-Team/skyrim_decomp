// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapFlags
#pragma once
enum class HeapFlags : int {
    kNone = 0,
    kThreadUnsafe = 1,
    kFastTinyBlocks = 2,
    kFixedGranularity = 4,
    kRoot = 8,
    kNoDebugInfo = 16,
    kUserDebug = 4096,
};
