// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TriangleFlag
#pragma once
enum class TriangleFlag : int {
    kNone = 0,
    kEdge0_Link = 1,
    kEdge1_Link = 2,
    kEdge2_Link = 4,
    kDeleted = 8,
    kNoLargeCreatures = 16,
    kOverlapping = 32,
    kPreferred = 64,
};
