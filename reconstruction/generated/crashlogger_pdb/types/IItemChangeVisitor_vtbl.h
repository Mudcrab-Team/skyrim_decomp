// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IItemChangeVisitor_vtbl; size 0x20
#pragma once
struct IItemChangeVisitor_vtbl {
    void (*_dtor_IItemChangeVisitor)(void);
    void (*Visit)(char32_t* , char32_t* , char32_t* , unsigned char* );
    bool (*ShouldVisit)(char32_t* , char32_t* );
    void (*Unk_03)(void);
};
static_assert(sizeof(IItemChangeVisitor_vtbl) == 32, "IItemChangeVisitor_vtbl layout differs from the PDB");
