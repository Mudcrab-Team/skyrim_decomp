// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeCollectionFilter_vtbl; size 0x20
#pragma once
struct hkpShapeCollectionFilter_vtbl {
    bool (*IsCollisionEnabled1)(char32_t* , char32_t* , char32_t* , char32_t* , char32_t* );
    bool (*IsCollisionEnabled2)(char32_t* , char32_t* , char32_t* , char32_t* , char32_t* , char32_t* , char32_t* );
    int (*NumShapeKeyHitsLimitBreached)(char32_t* , char32_t* , char32_t* , char32_t* , char32_t* , char32_t* , int);
    void (*_dtor_hkpShapeCollectionFilter)(void);
};
static_assert(sizeof(hkpShapeCollectionFilter_vtbl) == 32, "hkpShapeCollectionFilter_vtbl layout differs from the PDB");
