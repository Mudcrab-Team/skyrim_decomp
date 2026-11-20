// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CallbackProcessor_vtbl; size 0x10
#pragma once
struct CallbackProcessor_vtbl {
    void (*_dtor_CallbackProcessor)(void);
    bool (*Process)(void);
};
static_assert(sizeof(CallbackProcessor_vtbl) == 16, "CallbackProcessor_vtbl layout differs from the PDB");
