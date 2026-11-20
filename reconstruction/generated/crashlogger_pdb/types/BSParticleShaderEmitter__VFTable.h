// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderEmitter__VFTable; size 0x20
#pragma once

struct NiRefObject;
struct BSParticleShaderEmitter__VFTable {
    unsigned long long*(*dtor_0)(NiRefObject* , char);
    int (*Delete_8)(int (*)(unsigned long long, unsigned long long));
    long long (*Func2_10)(void);
    int (*Func3_18)(void);
};
static_assert(sizeof(BSParticleShaderEmitter__VFTable) == 32, "BSParticleShaderEmitter__VFTable layout differs from the PDB");
