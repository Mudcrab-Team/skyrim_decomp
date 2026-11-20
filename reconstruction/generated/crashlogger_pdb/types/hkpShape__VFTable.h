// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShape__VFTable; size 0x58
#pragma once

struct hkBaseObject_67f706b6;
union m128;
struct hkpShape__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    int (*Func3_18)(long long, m128* , long long);
    long long (*Func4_20)(void);
    char (*Func5_28)(void);
    long long (*Func6_30)(void);
    int (*Func7_38)(void);
    int (*Func8_40)(void);
    int (*Func9_48)(void);
    unsigned long long*(*Func10_50)(long long* , unsigned long long* , long long, long long, m128* );
};
static_assert(sizeof(hkpShape__VFTable) == 88, "hkpShape__VFTable layout differs from the PDB");
