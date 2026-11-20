// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmesh__VFTable; size 0x10
#pragma once

struct BSNavmesh;
struct BSNavmesh__VFTable {
    long long (*dtor_0)(BSNavmesh* , char);
    long long (*QNavmeshId_8)(BSNavmesh* );
};
static_assert(sizeof(BSNavmesh__VFTable) == 16, "BSNavmesh__VFTable layout differs from the PDB");
