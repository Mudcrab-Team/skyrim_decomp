// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SkyObject_vtbl; size 0x20
#pragma once
struct SkyObject_vtbl {
    void (*_dtor_SkyObject)(void);
    char32_t*(*GetRoot)(void);
    void (*Init)(char32_t* );
    void (*Update)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(SkyObject_vtbl) == 32, "SkyObject_vtbl layout differs from the PDB");
