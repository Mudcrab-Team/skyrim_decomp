// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicItemData_vtbl; size 0x38
#pragma once
struct MagicItemData_vtbl {
    void (*_dtor_MagicItemData)(void);
    void (*GetName)(void);
    unsigned int (*GetCount)(void);
    unsigned int (*GetEquipState)(void);
    unsigned int (*GetFilterFlag)(void);
    unsigned int (*GetFavorite)(void);
    bool (*GetEnabled)(void);
};
static_assert(sizeof(MagicItemData_vtbl) == 56, "MagicItemData_vtbl layout differs from the PDB");
