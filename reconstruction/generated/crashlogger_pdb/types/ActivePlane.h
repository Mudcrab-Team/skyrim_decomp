// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActivePlane
#pragma once
enum class ActivePlane : int {
    kNear = 1,
    kFar = 2,
    kLeft = 4,
    kRight = 8,
    kTop = 16,
    kBottom = 32,
};
