// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFloatData; size 0x28
#pragma once

#include "KeyType.h"
#include "NiObject_de5bc370.h"
struct NiFloatKey;
struct NiFloatData {
    NiObject_de5bc370 _base;
    unsigned int numKeys;
    unsigned int pad14;
    NiFloatKey* keys;
    KeyType type;
    unsigned char keySize;
    unsigned char pad25;
    unsigned short pad26;
};
static_assert(sizeof(NiFloatData) == 40, "NiFloatData layout differs from the PDB");
