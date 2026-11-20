// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantomListener_vtbl; size 0x28
#pragma once
struct hkpPhantomListener_vtbl {
    void (*_dtor_hkpPhantomListener)(void);
    void (*PhantomAddedCallback)(char32_t* );
    void (*PhantomRemovedCallback)(char32_t* );
    void (*PhantomShapeSetCallback)(char32_t* );
    void (*PhantomDeletedCallback)(char32_t* );
};
static_assert(sizeof(hkpPhantomListener_vtbl) == 40, "hkpPhantomListener_vtbl layout differs from the PDB");
