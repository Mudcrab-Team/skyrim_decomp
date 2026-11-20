// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiColorData; size 0x28
#pragma once

#include "KeyType.h"
#include "NiObject_de5bc370.h"
struct NiColorKey;
struct NiColorData {
    NiObject_de5bc370 _base;
    unsigned int numKeys;
    unsigned int pad14;
    NiColorKey* keys;
    KeyType type;
    unsigned char keySize;
    unsigned char pad25;
    unsigned short pad26;
};
static_assert(sizeof(NiColorData) == 40, "NiColorData layout differs from the PDB");
