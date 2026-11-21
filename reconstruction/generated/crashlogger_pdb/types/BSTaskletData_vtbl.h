// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletData_vtbl; size 0x20
#pragma once
struct BSTaskletData_vtbl {
    void (*_dtor_BSTaskletData)(void);
    bool (*Func1)(void);
    void (*Func2)(void);
    void (*Func3)(void);
};
static_assert(sizeof(BSTaskletData_vtbl) == 32, "BSTaskletData_vtbl layout differs from the PDB");
