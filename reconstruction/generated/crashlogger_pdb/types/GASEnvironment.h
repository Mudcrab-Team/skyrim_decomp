// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GASEnvironment; size 0x1a0
#pragma once

#include "GFxLogBase_RE__GASEnvironment_2010614f.h"
#include "GNewOverrideBase_323_7f544416.h"
struct GASGlobalContext;
struct GFxSprite;
struct GASEnvironment {
    GFxLogBase_RE__GASEnvironment_2010614f _base;
    unsigned char undefined_8[1];
    GNewOverrideBase_323_7f544416 _base_GNewOverrideBase_323_;
    unsigned char undefined_a[6];
    void* unk010;
    unsigned long long unk018;
    void* unk020;
    void* unk028;
    unsigned long long unk030;
    void* unk038;
    void* unk040;
    void* unk048;
    unsigned long long unk050[19];
    GFxSprite* sprite;
    GASGlobalContext* globalContext;
    unsigned char version;
    unsigned char pad0F9[7];
    unsigned long long pad100[20];
};
static_assert(sizeof(GASEnvironment) == 416, "GASEnvironment layout differs from the PDB");
