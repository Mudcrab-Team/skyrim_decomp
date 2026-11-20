// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FxDelegateHandler__VFTable; size 0x10
#pragma once

struct FxDelegateHandler;
struct GRefCountImplCore;
struct FxDelegateHandler__VFTable {
    long long (*dtor_0)(GRefCountImplCore* , char);
    unsigned long long*(*dtor_8)(FxDelegateHandler* , char);
};
static_assert(sizeof(FxDelegateHandler__VFTable) == 16, "FxDelegateHandler__VFTable layout differs from the PDB");
