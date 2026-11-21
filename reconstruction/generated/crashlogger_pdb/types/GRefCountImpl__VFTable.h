// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountImpl__VFTable; size 0x8
#pragma once

struct GRefCountImplCore;
struct GRefCountImpl__VFTable {
    long long (*dtor_0)(GRefCountImplCore* , char);
};
static_assert(sizeof(GRefCountImpl__VFTable) == 8, "GRefCountImpl__VFTable layout differs from the PDB");
