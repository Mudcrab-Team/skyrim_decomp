// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTexture; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "FormatPrefs.h"
#include "NiObject_de5bc370.h"
struct NiTexture_b3b6b2ac {
    NiObject_de5bc370 _base;
    FormatPrefs formatPrefs;
    BSFixedString_char_83b572b4 name;
    unsigned int unk28;
    unsigned int unk2C;
    NiTexture_b3b6b2ac* prev;
    NiTexture_b3b6b2ac* next;
};
static_assert(sizeof(NiTexture_b3b6b2ac) == 64, "NiTexture_b3b6b2ac layout differs from the PDB");
