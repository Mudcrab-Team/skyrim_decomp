// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshTriangle; size 0x10
// one of 2 different PDB types sharing this name
#pragma once
struct BSNavmeshTriangle_4576fddd {
    unsigned short Vertices_0[3];
    unsigned short Triangles_6[3];
    unsigned short triangleFlags;  // TriangleFlag in the PDB is wider than this slot
    unsigned short traversalFlags;  // TraversalFlag in the PDB is wider than this slot
};
static_assert(sizeof(BSNavmeshTriangle_4576fddd) == 16, "BSNavmeshTriangle_4576fddd layout differs from the PDB");
