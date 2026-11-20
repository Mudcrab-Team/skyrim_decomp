// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCamera_vtbl; size 0x18
#pragma once
struct TESCamera_vtbl {
    void (*_dtor_TESCamera)(void);
    void (*SetCameraRoot)(char32_t* );
    void (*Update)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(TESCamera_vtbl) == 24, "TESCamera_vtbl layout differs from the PDB");
