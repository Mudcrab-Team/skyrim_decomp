// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkVtableClassRegistry__VFTable; size 0x30
#pragma once

struct hkBaseObject_67f706b6;
struct hkVtableClassRegistry;
struct hkVtableClassRegistry__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    long long (*Func3_18)(hkVtableClassRegistry* , unsigned long long, long long);
    long long (*Func4_20)(hkVtableClassRegistry* , unsigned long long* );
    unsigned long long*(*Func5_28)(hkVtableClassRegistry* , long long);
};
static_assert(sizeof(hkVtableClassRegistry__VFTable) == 48, "hkVtableClassRegistry__VFTable layout differs from the PDB");
