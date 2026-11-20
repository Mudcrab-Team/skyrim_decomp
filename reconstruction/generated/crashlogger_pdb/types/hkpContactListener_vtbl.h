// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactListener_vtbl; size 0x38
#pragma once
struct hkpContactListener_vtbl {
    void (*ContactPointCallback)(char32_t* );
    void (*CollisionAddedCallback)(char32_t* );
    void (*CollisionRemovedCallback)(char32_t* );
    void (*_dtor_hkpContactListener)(void);
    void (*ContactPointAddedCallback)(char32_t* );
    void (*ContactPointRemovedCallback)(char32_t* );
    void (*ContactProcessCallback)(char32_t* );
};
static_assert(sizeof(hkpContactListener_vtbl) == 56, "hkpContactListener_vtbl layout differs from the PDB");
