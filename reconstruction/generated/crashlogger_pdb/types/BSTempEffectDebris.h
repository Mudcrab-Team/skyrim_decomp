// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTempEffectDebris; size 0x48
#pragma once

#include "BSTempEffect.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct BSTempEffectDebris {
    BSTempEffect _base;
    NiPointer_RE__NiAVObject_9e3aa701 debris3D;
    unsigned char* debrisFileName;
    bool unk40;
    unsigned char unk41;
    unsigned char pad42;
    unsigned char pad43;
    unsigned int pad44;
};
static_assert(sizeof(BSTempEffectDebris) == 72, "BSTempEffectDebris layout differs from the PDB");
