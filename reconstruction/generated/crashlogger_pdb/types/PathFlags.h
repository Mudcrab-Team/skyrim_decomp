// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PathFlags
#pragma once
enum class PathFlags : int {
    kNone = 0,
    kZoomDisable = 1,
    kZoomShotList = 2,
    kDynamicTimes = 4,
    kRandomPaths = 64,
    kAllowNoShots = 128,
};
