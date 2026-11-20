// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResourceReport_vtbl; size 0x20
#pragma once
struct GFxResourceReport_vtbl {
    void (*_dtor_GFxResourceReport)(void);
    void (*GetResourceName)(void);
    char32_t*(*GetResourceHeap)(void);
    void (*GetStats)(char32_t* , bool);
};
static_assert(sizeof(GFxResourceReport_vtbl) == 32, "GFxResourceReport_vtbl layout differs from the PDB");
