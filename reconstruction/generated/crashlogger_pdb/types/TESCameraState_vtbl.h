// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCameraState_vtbl; size 0x48
#pragma once
struct TESCameraState_vtbl {
    void (*_dtor_TESCameraState)(void);
    void (*Begin)(void);
    void (*End)(void);
    void (*Update)(char32_t* , char32_t* , char32_t* );
    void (*GetRotation)(char32_t* );
    void (*GetTranslation)(char32_t* );
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    void (*Revert)(char32_t* );
};
static_assert(sizeof(TESCameraState_vtbl) == 72, "TESCameraState_vtbl layout differs from the PDB");
