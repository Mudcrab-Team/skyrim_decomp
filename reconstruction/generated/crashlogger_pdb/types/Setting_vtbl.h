// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Setting_vtbl; size 0x10
#pragma once
struct Setting_vtbl {
    void (*_dtor_Setting)(void);
    bool (*IsPreferenceSetting)(void);
};
static_assert(sizeof(Setting_vtbl) == 16, "Setting_vtbl layout differs from the PDB");
