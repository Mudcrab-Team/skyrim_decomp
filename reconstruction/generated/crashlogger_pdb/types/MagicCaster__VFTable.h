// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicCaster__VFTable; size 0xe8
#pragma once

struct ActorMagicCaster;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct MagicCaster_274caf29;
struct MagicItem;
struct MagicCaster__VFTable {
    unsigned long long*(*dtor_0)(MagicCaster_274caf29* , long long, long long, long long);
    long long (*Func1_8)(MagicItem* , ActorMagicCaster* , char, long long, int, int, char, int);
    long long (*Func2_10)(ActorMagicCaster* , float);
    char (*Func3_18)(ActorMagicCaster* );
    char (*Func4_20)(ActorMagicCaster* );
    int (*Func5_28)(long long);
    char (*Func6_30)(ActorMagicCaster* , long long, long long, long long);
    void (*Func7_38)(void);
    void (*Func8_40)(void);
    void (*Func9_48)(void);
    char (*Func10_50)(long long, long long, long long, unsigned int* , unsigned int* );
    long long (*GetOwner_58)(void);
    long long (*GetOwner2_60)(void);
    int (*Func13_68)(ActorMagicCaster* , unsigned long long* );
    long long (*GetEffectNode_70)(void);
    void (*ClearEffectNode_78)(void);
    void (*Func16_80)(void);
    void (*Func17_88)(void);
    void (*Func18_90)(void);
    void (*Func19_98)(void);
    void (*Func20_A0)(ActorMagicCaster* , int);
    long long (*Func21_A8)(void);
    char (*Func22_B0)(void);
    void (*Func23_B8)(void);
    void*(*Func24_C0)(ActorMagicCaster* , BGSSaveFormBuffer* );
    char*(*Func25_C8)(long long, BGSLoadGameBuffer* );
    int (*Func26_D0)(long long);
    void (*Func27_D8)(unsigned int, long long, MagicItem* , float);
    void (*Func28_E0)(long long, long long, long long, unsigned char);
};
static_assert(sizeof(MagicCaster__VFTable) == 232, "MagicCaster__VFTable layout differs from the PDB");
