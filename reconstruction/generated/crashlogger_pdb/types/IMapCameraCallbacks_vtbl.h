// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMapCameraCallbacks_vtbl; size 0x18
#pragma once
struct IMapCameraCallbacks_vtbl {
    int (*Unk_00)(void* );
    void (*Unk_01)(void);
    void (*_dtor_IMapCameraCallbacks)(void);
};
static_assert(sizeof(IMapCameraCallbacks_vtbl) == 24, "IMapCameraCallbacks_vtbl layout differs from the PDB");
