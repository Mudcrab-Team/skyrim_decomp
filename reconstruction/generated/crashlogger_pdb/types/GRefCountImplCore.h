// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountImplCore; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct GRefCountImplCore__VFTable;
struct GRefCountImplCore {
    GRefCountImplCore__VFTable* vftable_GRefCountImplCore_0;
    int RefCount_8;
    char _pad_C[4];
};
static_assert(sizeof(GRefCountImplCore) == 16, "GRefCountImplCore layout differs from the PDB");
