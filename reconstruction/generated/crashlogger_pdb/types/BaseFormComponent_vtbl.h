// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BaseFormComponent_vtbl; size 0x20
#pragma once
struct BaseFormComponent_vtbl {
    void (*_dtor_BaseFormComponent)(void);
    void (*InitializeDataComponent)(void);
    void (*ClearDataComponent)(void);
    void (*CopyComponent)(char32_t* );
};
static_assert(sizeof(BaseFormComponent_vtbl) == 32, "BaseFormComponent_vtbl layout differs from the PDB");
