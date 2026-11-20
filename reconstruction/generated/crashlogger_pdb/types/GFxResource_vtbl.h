// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResource_vtbl; size 0x20
#pragma once
struct GFxResource_vtbl {
    void (*_dtor_GFxResource)(void);
    void (*GetKey)(void);
    unsigned int (*GetResourceTypeCode)(void);
    char32_t*(*GetResourceReport)(void);
};
static_assert(sizeof(GFxResource_vtbl) == 32, "GFxResource_vtbl layout differs from the PDB");
