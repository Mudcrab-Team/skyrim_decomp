// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshTriangle; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSNavmeshTriangle {
    unsigned short vertices[3];
    unsigned short triangles[3];
    unsigned short triangleFlags;  // TriangleFlag in the PDB is wider than this slot
    unsigned short traversalFlags;  // TraversalFlag in the PDB is wider than this slot
};
static_assert(sizeof(BSNavmeshTriangle) == 16, "BSNavmeshTriangle layout differs from the PDB");
