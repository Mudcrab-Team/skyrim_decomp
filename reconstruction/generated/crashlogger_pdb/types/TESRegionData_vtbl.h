// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionData_vtbl; size 0x40
#pragma once

#include "hkpPhantomType.h"
struct TESRegionData_vtbl {
    void (*_dtor_TESRegionData)(void);
    bool (*LoadDataHeader)(void* );
    void (*LoadData)(char32_t* );
    hkpPhantomType (*GetType)(void);
    void (*ConstructSelf)(void);
    void (*Unk_05)(void);
    void (*CopyFrom)(char32_t* , bool);
    bool (*IsLoaded)(void);
};
static_assert(sizeof(TESRegionData_vtbl) == 64, "TESRegionData_vtbl layout differs from the PDB");
