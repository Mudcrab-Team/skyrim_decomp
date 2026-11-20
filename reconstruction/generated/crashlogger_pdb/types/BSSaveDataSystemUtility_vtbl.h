// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSaveDataSystemUtility_vtbl; size 0x28
#pragma once
struct BSSaveDataSystemUtility_vtbl {
    void (*_dtor_BSSaveDataSystemUtility)(void);
    bool (*CreateSaveDirectory)(unsigned char* , bool);
    void (*PrepareFileSavePath)(unsigned char* , unsigned char* , bool, bool);
    void (*Unk_03)(void);
    void (*Unk_04)(void);
};
static_assert(sizeof(BSSaveDataSystemUtility_vtbl) == 40, "BSSaveDataSystemUtility_vtbl layout differs from the PDB");
