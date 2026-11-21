// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SyncQueueObj; size 0x10
#pragma once

#include "BSIntrusiveRefCounted.h"
struct SyncQueueObj_vtbl;
struct SyncQueueObj {
    SyncQueueObj_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int unk0C;
};
static_assert(sizeof(SyncQueueObj) == 16, "SyncQueueObj layout differs from the PDB");
