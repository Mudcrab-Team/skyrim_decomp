// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintInstance__VFTable; size 0x38
#pragma once

struct hkBaseObject_67f706b6;
struct hkpConstraintInstance;
struct hkpConstraintInstance__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    void (*Func3_18)(void);
    void (*Func4_20)(hkpConstraintInstance* , long long);
    void (*Func5_28)(void);
    long long (*Func6_30)(void);
};
static_assert(sizeof(hkpConstraintInstance__VFTable) == 56, "hkpConstraintInstance__VFTable layout differs from the PDB");
