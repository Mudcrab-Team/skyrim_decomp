// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IPackageData__VFTable; size 0x68
#pragma once

struct IPackageData_f084603b;
struct IPackageData__VFTable {
    unsigned long long*(*dtor_0)(IPackageData_f084603b* , char);
    int (*InitPackage_8)(void);
    int (*LoadPackage_10)(void);
    int (*Assign_18)(void);
    int (*IsNotEqual_20)(void);
    int (*Func5_28)(void);
    void (*Func6_30)(void);
    void (*Func7_38)(void);
    void (*LoadBuffer_40)(void);
    void (*Func9_48)(void);
    int (*GetDataAsString_50)(void);
    int (*GetTypeName_58)(void);
    char (*Func12_60)(void);
};
static_assert(sizeof(IPackageData__VFTable) == 104, "IPackageData__VFTable layout differs from the PDB");
