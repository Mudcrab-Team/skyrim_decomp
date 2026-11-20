// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Capabilities
#pragma once
enum class Capabilities : int {
    kNone = 0,
    kRayCast = 1,
    kLinearCast = 2,
    kAABBQuery = 4,
    kClosestPoints = 8,
    kCharProxyInt = 16,
    kISASweepAndPrune = 4096,
};
