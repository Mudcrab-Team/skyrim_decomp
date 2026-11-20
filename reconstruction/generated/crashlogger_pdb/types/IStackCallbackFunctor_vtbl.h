// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IStackCallbackFunctor_vtbl; size 0x20
#pragma once
struct IStackCallbackFunctor_vtbl {
    void (*_dtor_IStackCallbackFunctor)(void);
    char32_t* fn_008;
    bool (*CanSave)(void);
    void (*SetObject)(char32_t* );
};
static_assert(sizeof(IStackCallbackFunctor_vtbl) == 32, "IStackCallbackFunctor_vtbl layout differs from the PDB");
