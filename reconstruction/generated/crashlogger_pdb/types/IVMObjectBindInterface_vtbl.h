// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IVMObjectBindInterface_vtbl; size 0x58
#pragma once
struct IVMObjectBindInterface_vtbl {
    void (*_dtor_IVMObjectBindInterface)(void);
    void (*GetBoundHandle)(char32_t* );
    bool (*TypeCanBeBound)(char32_t* , char32_t* );
    void (*BindObject)(char32_t* , char32_t* , bool);
    void (*HandleLoadedBinding)(char32_t* , char32_t* , bool);
    void (*RemoveAllBoundObjects)(char32_t* );
    void (*RemoveAllDiskLoadedBoundObjects)(char32_t* );
    void (*HandleCObjectDeletion)(char32_t* );
    void (*UnbindObject)(char32_t* );
    bool (*CreateObjectWithProperties)(char32_t* , unsigned int, char32_t* );
    bool (*InitObjectProperties)(char32_t* , void* , bool);
};
static_assert(sizeof(IVMObjectBindInterface_vtbl) == 88, "IVMObjectBindInterface_vtbl layout differs from the PDB");
