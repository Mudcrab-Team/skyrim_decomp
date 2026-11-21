// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IProcedureTreeItem_vtbl; size 0x88
#pragma once
struct IProcedureTreeItem_vtbl {
    void (*_dtor_IProcedureTreeItem)(void);
    void (*Unk_01)(void);
    void (*Unk_02)(void);
    bool (*Load)(char32_t* );
    void (*Execute)(char32_t* );
    void (*Unk_05)(void);
    void (*Unk_06)(void);
    void (*Unk_07)(void);
    void (*Unk_08)(void);
    void (*Unk_09)(void);
    void (*Unk_0A)(void);
    void (*Unk_0B)(void);
    void (*Unk_0C)(void);
    void (*Unk_0D)(void);
    void (*Unk_0E)(void);
    void (*Unk_0F)(void);
    unsigned int (*Unk_10)(void);
};
static_assert(sizeof(IProcedureTreeItem_vtbl) == 136, "IProcedureTreeItem_vtbl layout differs from the PDB");
