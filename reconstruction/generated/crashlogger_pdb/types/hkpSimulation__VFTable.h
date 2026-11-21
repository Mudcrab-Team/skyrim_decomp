// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimulation__VFTable; size 0x98
#pragma once

struct ahkpWorld;
struct hkBaseObject_67f706b6;
struct hkpContinuousSimulation;
struct hkpSimulation;
struct hkpSimulation__VFTable {
    void (*dtor_0)(hkBaseObject_67f706b6* );
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    long long (*Func3_18)(hkpSimulation* );
    long long (*Func4_20)(hkpSimulation* , float);
    long long (*Func5_28)(hkpSimulation* );
    long long (*Func6_30)(long long, float);
    long long (*Func7_38)(void);
    long long (*Func8_40)(void);
    void (*Func9_48)(void);
    void (*Func10_50)(void);
    void (*Func11_58)(int, long long, unsigned int, long long, unsigned long long* );
    int (*Func12_60)(hkpContinuousSimulation* , void* , long long, ahkpWorld* , char);
    void (*Func13_68)(void);
    void (*Func14_70)(void);
    void (*Func15_78)(void);
    void (*Func16_80)(long long* , long long, int, long long, float, char);
    unsigned long long*(*Func17_88)(hkpSimulation* , long long);
    void (*Func18_90)(void);
};
static_assert(sizeof(hkpSimulation__VFTable) == 152, "hkpSimulation__VFTable layout differs from the PDB");
