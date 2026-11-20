// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterProxyListener_vtbl; size 0x30
#pragma once
struct hkpCharacterProxyListener_vtbl {
    void (*_dtor_hkpCharacterProxyListener)(void);
    void (*ProcessConstraintsCallback)(char32_t* , char32_t* , char32_t* );
    void (*ContactPointAddedCallback)(char32_t* );
    void (*ContactPointRemovedCallback)(char32_t* );
    void (*CharacterInteractionCallback)(char32_t* , char32_t* , char32_t* );
    void (*ObjectInteractionCallback)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(hkpCharacterProxyListener_vtbl) == 48, "hkpCharacterProxyListener_vtbl layout differs from the PDB");
