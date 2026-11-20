// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ILoader; size 0x8
#pragma once

struct ILoader_vtbl;
struct ILoader {
    ILoader_vtbl* __vftable;
};
static_assert(sizeof(ILoader) == 8, "ILoader layout differs from the PDB");
