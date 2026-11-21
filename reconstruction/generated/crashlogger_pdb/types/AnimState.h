// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimState
#pragma once
enum class AnimState : int {
    kInactive = 0,
    kAnimating = 1,
    kEaseIn = 2,
    kEaseOut = 3,
    kTransSource = 4,
    kTransDest = 5,
    kMorphSource = 6,
};
