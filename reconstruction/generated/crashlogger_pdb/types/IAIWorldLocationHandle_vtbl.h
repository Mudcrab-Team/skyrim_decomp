// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IAIWorldLocationHandle_vtbl; size 0x20
#pragma once
struct IAIWorldLocationHandle_vtbl {
    void (*_dtor_IAIWorldLocationHandle)(void);
    char32_t*(*AllocateLocation)(char32_t* );
    char32_t*(*GetAsPackageLocation)(void);
    bool (*IsRefAtLocation)(char32_t* , char32_t* );
};
static_assert(sizeof(IAIWorldLocationHandle_vtbl) == 32, "IAIWorldLocationHandle_vtbl layout differs from the PDB");
