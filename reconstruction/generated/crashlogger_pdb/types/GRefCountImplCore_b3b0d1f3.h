// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountImplCore; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct GRefCountImplCore_vtbl;
struct GRefCountImplCore_b3b0d1f3 {
    GRefCountImplCore_vtbl* __vftable;
    unsigned int _refCount;
    unsigned int _pad0C;
};
static_assert(sizeof(GRefCountImplCore_b3b0d1f3) == 16, "GRefCountImplCore_b3b0d1f3 layout differs from the PDB");
