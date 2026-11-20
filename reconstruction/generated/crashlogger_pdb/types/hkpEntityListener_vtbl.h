// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntityListener_vtbl; size 0x30
#pragma once
struct hkpEntityListener_vtbl {
    void (*_dtor_hkpEntityListener)(void);
    void (*EntityAddedCallback)(char32_t* );
    void (*EntityRemovedCallback)(char32_t* );
    void (*EntityShapeSetCallback)(char32_t* );
    void (*EntitySetMotionTypeCallback)(char32_t* );
    void (*EntityDeletedCallback)(char32_t* );
};
static_assert(sizeof(hkpEntityListener_vtbl) == 48, "hkpEntityListener_vtbl layout differs from the PDB");
