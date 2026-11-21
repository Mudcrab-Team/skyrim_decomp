// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RESET_3D_FLAGS
#pragma once
enum class RESET_3D_FLAGS : int {
    kNone = 0,
    kModel = 1,
    kSkin = 2,
    kHead = 4,
    kFace = 8,
    kScale = 16,
    kSkeleton = 32,
    kInitDefault = 64,
    kSkyCellSkin = 128,
};
