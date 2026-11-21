// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NameMapData; size 0x10
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct NameMapData {
    BSFixedString_char_83b572b4 name;
    unsigned char uid;
    bool isPublic;
    unsigned char pad0A;
    unsigned char pad0B;
    unsigned int pad0C;
};
static_assert(sizeof(NameMapData) == 16, "NameMapData layout differs from the PDB");
