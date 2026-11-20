// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CategoryListEntry_vtbl; size 0x28
#pragma once
struct CategoryListEntry_vtbl {
    void (*_dtor_CategoryListEntry)(void);
    void (*ShowInItemCard)(char32_t* );
    void (*ShowItem3D)(bool);
    unsigned char*(*GetName)(void);
    void (*SetData)(char32_t* );
};
static_assert(sizeof(CategoryListEntry_vtbl) == 40, "CategoryListEntry_vtbl layout differs from the PDB");
