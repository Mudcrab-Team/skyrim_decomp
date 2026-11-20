// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IVirtualMachine; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IVirtualMachine_vtbl;
struct IVirtualMachine {
    IVirtualMachine_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IVirtualMachine) == 16, "IVirtualMachine layout differs from the PDB");
