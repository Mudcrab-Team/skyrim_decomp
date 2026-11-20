// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FxDelegate__VFTable; size 0x10
#pragma once

struct FxDelegate;
struct FxDelegate__VFTable {
    unsigned long long*(*dtor_0)(FxDelegate* , char);
    int (*Callback_8)(FxDelegate* , long long, long long, long long, int);
};
static_assert(sizeof(FxDelegate__VFTable) == 16, "FxDelegate__VFTable layout differs from the PDB");
