// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidableCollidableFilter_vtbl; size 0x10
#pragma once
struct hkpCollidableCollidableFilter_vtbl {
    void (*_dtor_hkpCollidableCollidableFilter)(void);
    bool (*IsCollisionEnabled)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(hkpCollidableCollidableFilter_vtbl) == 16, "hkpCollidableCollidableFilter_vtbl layout differs from the PDB");
