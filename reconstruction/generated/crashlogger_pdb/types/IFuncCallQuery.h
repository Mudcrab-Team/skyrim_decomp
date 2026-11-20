// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFuncCallQuery; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IFuncCallQuery_vtbl;
struct IFuncCallQuery {
    IFuncCallQuery_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IFuncCallQuery) == 16, "IFuncCallQuery layout differs from the PDB");
