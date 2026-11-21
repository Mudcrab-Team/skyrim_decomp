// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTriangleShape__VFTable; size 0x90
#pragma once

struct hkpTriangleShape;
union m128;
struct hkpTriangleShape__VFTable {
    long long (*Func0_0)(hkpTriangleShape* , char);
    long long (*Func1_8)(void);
    void (*Func2_10)(hkpTriangleShape* , long long);
    int (*Func3_18)(long long, m128* );
    long long (*Func4_20)(void);
    char (*Func5_28)(void);
    long long (*Func6_30)(void);
    char _pad_38[8];
    unsigned char*(*Func8_40)(hkpTriangleShape* , unsigned char* , long long, m128* );
    int (*Func9_48)(long long* , long long, long long, long long);
    char _pad_50[8];
    long long (*Func11_58)(hkpTriangleShape* );
    long long (*Func12_60)(hkpTriangleShape* , long long);
    void (*Func13_68)(hkpTriangleShape* , unsigned long long* );
    long long (*Func14_70)(hkpTriangleShape* , m128* , m128* );
    long long (*Func15_78)(hkpTriangleShape* , unsigned short* , int, m128* );
    long long (*Func16_80)(long long, long long, long long, unsigned char* , m128* , long long, m128* );
    void (*Func17_88)(hkpTriangleShape* , m128* );
};
static_assert(sizeof(hkpTriangleShape__VFTable) == 144, "hkpTriangleShape__VFTable layout differs from the PDB");
