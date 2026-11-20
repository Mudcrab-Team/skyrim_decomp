// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorState__VFTable; size 0xb0
#pragma once

struct ActorState;
struct IMovementInterface;
struct ActorState__VFTable {
    long long (*dtor_0)(IMovementInterface* , char);
    int (*Func1_8)(void);
    int (*Func2_10)(void);
    int (*Func3_18)(void);
    int (*Func4_20)(void);
    int (*Func5_28)(void);
    int (*Func6_30)(void);
    int (*Func7_38)(void);
    int (*Func8_40)(void);
    int (*Func9_48)(void);
    int (*Func10_50)(void);
    int (*Func11_58)(void);
    int (*Func12_60)(void);
    int (*Func13_68)(void);
    int (*Func14_70)(void);
    int (*Func15_78)(void);
    int (*Func16_80)(void);
    int (*Func17_88)(void);
    int (*Func18_90)(void);
    int (*Func19_98)(void);
    char (*Func20_A0)(ActorState* , char);
    char (*Func21_A8)(long long, char, float);
};
static_assert(sizeof(ActorState__VFTable) == 176, "ActorState__VFTable layout differs from the PDB");
