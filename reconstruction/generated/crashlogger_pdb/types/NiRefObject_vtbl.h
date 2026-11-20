// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiRefObject_vtbl; size 0x10
#pragma once
struct NiRefObject_vtbl {
    void (*_dtor_NiRefObject)(void);
    void (*DeleteThis)(void);
};
static_assert(sizeof(NiRefObject_vtbl) == 16, "NiRefObject_vtbl layout differs from the PDB");
