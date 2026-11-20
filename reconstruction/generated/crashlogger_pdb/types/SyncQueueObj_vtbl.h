// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SyncQueueObj_vtbl; size 0x10
#pragma once
struct SyncQueueObj_vtbl {
    void (*_dtor_SyncQueueObj)(void);
    void (*Unk_01)(void);
};
static_assert(sizeof(SyncQueueObj_vtbl) == 16, "SyncQueueObj_vtbl layout differs from the PDB");
