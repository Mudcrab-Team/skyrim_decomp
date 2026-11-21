// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHazardFlags
#pragma once
enum class BGSHazardFlags : int {
    kNone = 0,
    kPCOnly = 1,
    kInheritDuration = 2,
    kAlignToNormal = 4,
    kInheritRadius = 8,
    kDropToGround = 16,
};
