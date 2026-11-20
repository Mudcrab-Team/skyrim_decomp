// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshCoverEdge; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct BSNavmeshCoverEdge {
    unsigned short vertices[2];
    unsigned int data;
};
static_assert(sizeof(BSNavmeshCoverEdge) == 8, "BSNavmeshCoverEdge layout differs from the PDB");
