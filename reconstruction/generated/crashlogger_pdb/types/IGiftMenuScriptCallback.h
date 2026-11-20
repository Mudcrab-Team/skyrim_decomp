// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IGiftMenuScriptCallback; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct IGiftMenuScriptCallback_vtbl;
struct IGiftMenuScriptCallback {
    IGiftMenuScriptCallback_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int pad0C;
};
static_assert(sizeof(IGiftMenuScriptCallback) == 16, "IGiftMenuScriptCallback layout differs from the PDB");
