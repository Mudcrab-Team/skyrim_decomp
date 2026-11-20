// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayShapeCollectionFilter_vtbl; size 0x10
#pragma once
struct hkpRayShapeCollectionFilter_vtbl {
    bool (*IsCollisionEnabled)(char32_t* , char32_t* , char32_t* );
    void (*_dtor_hkpRayShapeCollectionFilter)(void);
};
static_assert(sizeof(hkpRayShapeCollectionFilter_vtbl) == 16, "hkpRayShapeCollectionFilter_vtbl layout differs from the PDB");
