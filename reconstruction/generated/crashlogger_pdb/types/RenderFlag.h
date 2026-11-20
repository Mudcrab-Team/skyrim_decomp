// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RenderFlag
#pragma once
enum class RenderFlag : int {
    kNone = 0,
    kStrokeNormal = 1,
    kStrokeHairline = 2,
    kStrokeMask = 3,
    kEdgeAA = 16,
    kOptimizeTriangles = 32,
    kNoViewCull = 256,
};
