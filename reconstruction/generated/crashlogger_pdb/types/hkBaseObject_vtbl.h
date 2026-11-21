// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkBaseObject_vtbl; size 0x8
#pragma once
struct hkBaseObject_vtbl {
    void (*_dtor_hkBaseObject)(void);
};
static_assert(sizeof(hkBaseObject_vtbl) == 8, "hkBaseObject_vtbl layout differs from the PDB");
