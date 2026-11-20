// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAction__VFTable; size 0x40
#pragma once

struct hkBaseObject_67f706b6;
struct hkpAction__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    int (*Func3_18)(void);
    int (*Func4_20)(void);
    void (*Func5_28)(void);
    int (*Func6_30)(void);
    int (*Func7_38)(void);
};
static_assert(sizeof(hkpAction__VFTable) == 64, "hkpAction__VFTable layout differs from the PDB");
