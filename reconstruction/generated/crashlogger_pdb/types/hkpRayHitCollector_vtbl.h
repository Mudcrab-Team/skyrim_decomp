// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayHitCollector_vtbl; size 0x10
#pragma once
struct hkpRayHitCollector_vtbl {
    void (*AddRayHit)(char32_t* , char32_t* );
    void (*_dtor_hkpRayHitCollector)(void);
};
static_assert(sizeof(hkpRayHitCollector_vtbl) == 16, "hkpRayHitCollector_vtbl layout differs from the PDB");
