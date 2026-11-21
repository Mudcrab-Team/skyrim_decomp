// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IExplosionFactory_vtbl; size 0x10
#pragma once
struct IExplosionFactory_vtbl {
    void (*_dtor_IExplosionFactory)(void);
    char32_t*(*Create)(char32_t* );
};
static_assert(sizeof(IExplosionFactory_vtbl) == 16, "IExplosionFactory_vtbl layout differs from the PDB");
