// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OcclusionQuery; size 0x8
#pragma once

struct ID3D11Query;
struct OcclusionQuery {
    ID3D11Query* query;
};
static_assert(sizeof(OcclusionQuery) == 8, "OcclusionQuery layout differs from the PDB");
