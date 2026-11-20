// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESChildCell_vtbl; size 0x10
#pragma once
struct TESChildCell_vtbl {
    void (*_dtor_TESChildCell)(void);
    char32_t*(*GetSaveParentCell)(void);
};
static_assert(sizeof(TESChildCell_vtbl) == 16, "TESChildCell_vtbl layout differs from the PDB");
