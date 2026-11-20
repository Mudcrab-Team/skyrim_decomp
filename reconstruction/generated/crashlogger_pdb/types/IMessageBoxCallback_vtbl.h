// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMessageBoxCallback_vtbl; size 0x10
#pragma once
struct IMessageBoxCallback_vtbl {
    void (*_dtor_IMessageBoxCallback)(void);
    void (*Run)(unsigned char);
};
static_assert(sizeof(IMessageBoxCallback_vtbl) == 16, "IMessageBoxCallback_vtbl layout differs from the PDB");
