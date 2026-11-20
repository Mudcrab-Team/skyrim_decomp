// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiFlags
#pragma once
enum class ActiFlags : int {
    kNone = 0,
    kNoDisplacement = 1,
    kIgnoredBySandbox = 2,
    kIsProceduralWater = 4,
    kIsLODWater = 8,
};
