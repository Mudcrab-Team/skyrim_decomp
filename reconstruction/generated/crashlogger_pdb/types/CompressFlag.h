// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CompressFlag
#pragma once
enum class CompressFlag : int {
    kNorm = 1,
    kColor = 2,
    kUV = 4,
    kWeight = 8,
    kPosition = 16,
    kAll = 31,
};
