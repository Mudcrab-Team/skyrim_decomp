// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: VertexDesc; size 0x8
#pragma once
struct VertexDesc {
    unsigned long long desc;
};
static_assert(sizeof(VertexDesc) == 8, "VertexDesc layout differs from the PDB");
