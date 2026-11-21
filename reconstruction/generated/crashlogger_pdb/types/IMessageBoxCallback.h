// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMessageBoxCallback; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IMessageBoxCallback_vtbl;
struct IMessageBoxCallback {
    IMessageBoxCallback_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IMessageBoxCallback) == 16, "IMessageBoxCallback layout differs from the PDB");
