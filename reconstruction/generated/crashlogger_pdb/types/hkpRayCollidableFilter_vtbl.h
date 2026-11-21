// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayCollidableFilter_vtbl; size 0x10
#pragma once
struct hkpRayCollidableFilter_vtbl {
    void (*_dtor_hkpRayCollidableFilter)(void);
    bool (*IsCollisionEnabled)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(hkpRayCollidableFilter_vtbl) == 16, "hkpRayCollidableFilter_vtbl layout differs from the PDB");
