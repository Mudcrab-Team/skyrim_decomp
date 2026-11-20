// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _Facet_base_vtbl; size 0x18
#pragma once

struct Facet_base;
struct Facet_base_vtbl {
    void (*_dtor__Facet_base)(void);
    void (*_Incref)(void);
    Facet_base*(*_Decref)(void);
};
static_assert(sizeof(Facet_base_vtbl) == 24, "Facet_base_vtbl layout differs from the PDB");
