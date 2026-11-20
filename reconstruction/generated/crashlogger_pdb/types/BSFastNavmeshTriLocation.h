// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFastNavmeshTriLocation; size 0x18
#pragma once

struct BSFastNavmeshTriLocation_vtbl;
struct BSNavmesh_712a9777;
struct BSFastNavmeshTriLocation {
    BSFastNavmeshTriLocation_vtbl* __vftable;
    BSNavmesh_712a9777* navMesh;
    unsigned short triIndex;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(BSFastNavmeshTriLocation) == 24, "BSFastNavmeshTriLocation layout differs from the PDB");
