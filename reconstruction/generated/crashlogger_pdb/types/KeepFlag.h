// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KeepFlag
#pragma once
enum class KeepFlag : int {
    kXYZ = 1,
    kNorm = 2,
    kColor = 4,
    kUV = 8,
    kIndices = 16,
    kBonedata = 32,
    kAll = 63,
};
