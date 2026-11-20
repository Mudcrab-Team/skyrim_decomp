// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFunction; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IFunction_vtbl;
struct IFunction {
    IFunction_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IFunction) == 16, "IFunction layout differs from the PDB");
