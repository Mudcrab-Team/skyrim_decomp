// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GAcquireInterface_vtbl; size 0x28
#pragma once
struct GAcquireInterface_vtbl {
    void (*_dtor_GAcquireInterface)(void);
    bool (*CanAcquire)(void);
    bool (*TryAcquire)(void);
    bool (*TryAcquireCommit)(void);
    bool (*TryAcquireCancel)(void);
};
static_assert(sizeof(GAcquireInterface_vtbl) == 40, "GAcquireInterface_vtbl layout differs from the PDB");
