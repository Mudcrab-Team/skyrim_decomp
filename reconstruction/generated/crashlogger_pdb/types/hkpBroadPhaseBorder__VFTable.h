// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhaseBorder__VFTable; size 0x28
#pragma once

struct hkBaseObject_67f706b6;
struct hkpBroadPhaseBorder;
struct hkpBroadPhaseBorder__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    void (*Func3_18)(hkpBroadPhaseBorder* , long long);
    int (*Func4_20)(hkpBroadPhaseBorder* );
};
static_assert(sizeof(hkpBroadPhaseBorder__VFTable) == 40, "hkpBroadPhaseBorder__VFTable layout differs from the PDB");
