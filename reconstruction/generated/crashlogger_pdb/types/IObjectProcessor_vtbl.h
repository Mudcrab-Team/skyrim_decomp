// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IObjectProcessor_vtbl; size 0x20
#pragma once
struct IObjectProcessor_vtbl {
    void (*_dtor_IObjectProcessor)(void);
    char32_t*(*Clone)(void);
    void (*SetLoader)(char32_t* );
    bool (*Process)(char32_t* );
};
static_assert(sizeof(IObjectProcessor_vtbl) == 32, "IObjectProcessor_vtbl layout differs from the PDB");
