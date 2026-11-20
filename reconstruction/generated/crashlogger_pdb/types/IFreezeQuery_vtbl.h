// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IFreezeQuery_vtbl; size 0x10
#pragma once
struct IFreezeQuery_vtbl {
    void (*_dtor_IFreezeQuery)(void);
    bool (*GetIsFrozen)(void);
};
static_assert(sizeof(IFreezeQuery_vtbl) == 16, "IFreezeQuery_vtbl layout differs from the PDB");
