// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshTriangleEdgePortal; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSNavmeshTriangleEdgePortal {
    unsigned int OtherMeshFormId_0;
    unsigned short Triangle_4;
    char EdgeIndex_6;
    char _pad_7;
};
static_assert(sizeof(BSNavmeshTriangleEdgePortal) == 8, "BSNavmeshTriangleEdgePortal layout differs from the PDB");
