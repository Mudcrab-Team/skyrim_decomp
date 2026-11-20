// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShader; size 0xf8
#pragma once

#include "BSShader.h"
struct BSLightingShader {
    BSShader _base;
    unsigned int unk90;
    unsigned int currentRawTechnique;
    unsigned long long unk98;
    unsigned long long unkA0;
    unsigned long long unkA8;
    unsigned long long unkB0;
    unsigned long long unkB8;
    unsigned long long unkC0;
    unsigned long long unkC8;
    unsigned long long unkD0;
    unsigned long long unkD8;
    unsigned long long unkE0;
    unsigned long long unkE8;
    unsigned long long unkF0;
};
static_assert(sizeof(BSLightingShader) == 248, "BSLightingShader layout differs from the PDB");
