// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldObject__VFTable; size 0x30
#pragma once

struct hkBaseObject_67f706b6;
struct hkpWorldObject__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    long long (*Func3_18)(void);
    long long (*Func4_20)(void);
    int (*Func5_28)(void);
};
static_assert(sizeof(hkpWorldObject__VFTable) == 48, "hkpWorldObject__VFTable layout differs from the PDB");
