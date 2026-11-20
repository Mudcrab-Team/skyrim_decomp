// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshTriangleEdgePortal; size 0x8
// one of 2 different PDB types sharing this name
#pragma once
struct BSNavmeshTriangleEdgePortal_6caa9608 {
    unsigned int otherMeshID;
    unsigned short triangle;
    unsigned char edgeIndex;
    unsigned char pad7;
};
static_assert(sizeof(BSNavmeshTriangleEdgePortal_6caa9608) == 8, "BSNavmeshTriangleEdgePortal_6caa9608 layout differs from the PDB");
