// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTempEffect; size 0x30
#pragma once

#include "NiObject_de5bc370.h"
struct TESObjectCELL_f81013b3;
struct BSTempEffect {
    NiObject_de5bc370 _base;
    float lifetime;
    unsigned int pad14;
    TESObjectCELL_f81013b3* cell;
    float age;
    bool initialized;
    unsigned char pad25;
    unsigned short pad26;
    unsigned int effectID;
    unsigned int pad2C;
};
static_assert(sizeof(BSTempEffect) == 48, "BSTempEffect layout differs from the PDB");
