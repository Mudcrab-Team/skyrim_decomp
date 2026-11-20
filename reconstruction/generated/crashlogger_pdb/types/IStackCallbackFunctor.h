// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IStackCallbackFunctor; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IStackCallbackFunctor_vtbl;
struct IStackCallbackFunctor {
    IStackCallbackFunctor_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IStackCallbackFunctor) == 16, "IStackCallbackFunctor layout differs from the PDB");
