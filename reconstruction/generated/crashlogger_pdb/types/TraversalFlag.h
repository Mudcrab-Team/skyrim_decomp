// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TraversalFlag
#pragma once
enum class TraversalFlag : int {
    kNone = 0,
    kEdge0_CoverValueQuarter = 1,
    kEdge0_CoverValueHalf = 2,
    kEdge0_CoverValueTri = 4,
    kEdge0_CoverValueFull = 8,
    kEdge0_Left = 16,
    kEdge0_Right = 32,
    kEdge1_CoverValueQuarter = 64,
    kEdge1_CoverValueHalf = 128,
    kEdge1_CoverValueTri = 256,
    kEdge1_CoverValueFull = 512,
    kEdge1_Left = 1024,
    kEdge1_Right = 2048,
};
