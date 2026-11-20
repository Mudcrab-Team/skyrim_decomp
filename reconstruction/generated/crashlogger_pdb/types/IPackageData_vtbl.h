// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IPackageData_vtbl; size 0x68
#pragma once
struct IPackageData_vtbl {
    void (*_dtor_IPackageData)(void);
    void (*InitPackage)(void);
    void (*LoadPackage)(char32_t* );
    void (*Assign)(char32_t* );
    bool (*IsNotEqual)(char32_t* );
    void (*Unk_05)(void);
    void (*Unk_06)(void);
    void (*Unk_07)(void);
    void (*LoadBuffer)(char32_t* );
    void (*Unk_09)(void);
    bool (*GetDataAsString)(char32_t* );
    char32_t*(*GetTypeName)(void);
    void (*Unk_0C)(void);
};
static_assert(sizeof(IPackageData_vtbl) == 104, "IPackageData_vtbl layout differs from the PDB");
