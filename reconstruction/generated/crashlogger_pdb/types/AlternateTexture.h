// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AlternateTexture; size 0x18
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct BGSTextureSet;
struct AlternateTexture {
    BGSTextureSet* textureSet;
    unsigned int index3D;
    unsigned int unk0C;
    BSFixedString_char_83b572b4 name3D;
};
static_assert(sizeof(AlternateTexture) == 24, "AlternateTexture layout differs from the PDB");
