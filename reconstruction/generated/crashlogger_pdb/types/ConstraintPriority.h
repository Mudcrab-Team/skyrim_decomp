// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ConstraintPriority
#pragma once
enum class ConstraintPriority : int {
    kInvalid = 0,
    kPSI = 1,
    kSimplifiedTOI_Unused = 2,
    kTOI = 3,
    kTOIHigher = 4,
    kTOIForced = 5,
    kTotal = 6,
};
