// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountImpl; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct GRefCountImpl__VFTable;
struct GRefCountImpl {
    GRefCountImpl__VFTable* vftable_GRefCountImpl_0;
    int RefCount_8;
    char _pad_C[4];
};
static_assert(sizeof(GRefCountImpl) == 16, "GRefCountImpl layout differs from the PDB");
