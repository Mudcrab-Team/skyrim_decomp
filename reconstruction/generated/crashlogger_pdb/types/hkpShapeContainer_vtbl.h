// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeContainer_vtbl; size 0x38
#pragma once
struct hkpShapeContainer_vtbl {
    void (*_dtor_hkpShapeContainer)(void);
    int (*GetNumChildShapes)(void);
    void (*GetFirstKey)(void);
    void (*GetNextKey)(char32_t* );
    void (*GetCollisionFilterInfo)(char32_t* );
    char32_t*(*GetChildShape)(char32_t* , char32_t* );
    bool (*IsWeldingEnabled)(void);
};
static_assert(sizeof(hkpShapeContainer_vtbl) == 56, "hkpShapeContainer_vtbl layout differs from the PDB");
