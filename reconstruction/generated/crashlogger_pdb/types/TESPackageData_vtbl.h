// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackageData_vtbl; size 0x30
#pragma once
struct TESPackageData_vtbl {
    void (*_dtor_TESPackageData)(void);
    void (*Copy)(char32_t* );
    int (*Compare)(char32_t* );
    void (*InitItem)(char32_t* );
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
};
static_assert(sizeof(TESPackageData_vtbl) == 48, "TESPackageData_vtbl layout differs from the PDB");
