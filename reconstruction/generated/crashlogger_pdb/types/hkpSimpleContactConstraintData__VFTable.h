// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleContactConstraintData__VFTable; size 0xa8
#pragma once

struct hkpSimpleContactConstraintData;
struct hkpTriangleShape;
union m128;
struct hkpSimpleContactConstraintData__VFTable {
    long long (*Func0_0)(hkpSimpleContactConstraintData* , char);
    long long (*Func1_8)(void);
    void (*Func2_10)(long long, long long, void* );
    void (*Func3_18)(void);
    void (*Func4_20)(void);
    void (*Func5_28)(void);
    long long (*Func6_30)(void);
    long long (*Func7_38)(void);
    void (*Func8_40)(void);
    char (*Func9_48)(void);
    unsigned char*(*Func10_50)(hkpSimpleContactConstraintData* , unsigned char* );
    long long (*Func11_58)(void);
    long long (*Func12_60)(hkpSimpleContactConstraintData* , long long, unsigned long long* );
    long long (*Func13_68)(void);
    void*(*Func14_70)(long long, long long, hkpTriangleShape* , unsigned int);
    void (*Func15_78)(void);
    unsigned char*(*Func16_80)(long long, unsigned char* );
    void (*Func17_88)(void);
    long long (*Func18_90)(hkpSimpleContactConstraintData* , long long);
    long long (*Func19_98)(hkpSimpleContactConstraintData* , long long, m128* , long long, m128* , m128* );
    void (*Func20_A0)(hkpSimpleContactConstraintData* , long long, long long, long long, long long, long long, m128* );
};
static_assert(sizeof(hkpSimpleContactConstraintData__VFTable) == 168, "hkpSimpleContactConstraintData__VFTable layout differs from the PDB");
