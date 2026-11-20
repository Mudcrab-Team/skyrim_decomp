// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DisabledPoint
#pragma once
enum class DisabledPoint : int {
    kNone = 0,
    kFront = 1,
    kBehind = 2,
    kRight = 4,
    kLeft = 8,
    kUp = 16,
};
