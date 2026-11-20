// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IGiftMenuScriptCallback_vtbl; size 0x10
#pragma once
struct IGiftMenuScriptCallback_vtbl {
    void (*_dtor_IGiftMenuScriptCallback)(void);
    void (*Run)(unsigned char);
};
static_assert(sizeof(IGiftMenuScriptCallback_vtbl) == 16, "IGiftMenuScriptCallback_vtbl layout differs from the PDB");
