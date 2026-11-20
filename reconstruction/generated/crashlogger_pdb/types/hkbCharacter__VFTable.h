// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbCharacter__VFTable; size 0x28
#pragma once

struct hkBaseObject_67f706b6;
struct hkbCharacter;
struct hkbCharacter__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    int (*Func3_18)(long long, long long, long long, long long, float, long long, int, char, char);
    long long (*Func4_20)(hkbCharacter* , float, long long);
};
static_assert(sizeof(hkbCharacter__VFTable) == 40, "hkbCharacter__VFTable layout differs from the PDB");
