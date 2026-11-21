// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSourceTexture; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiTexture__FormatPrefs.h"
struct NiSourceTexture__VFTable;
struct NiTexture;
struct NiSourceTexture {
    NiSourceTexture__VFTable* vftable_NiSourceTexture_0;
    char _pad_8[8];
    NiTexture__FormatPrefs Format_10;
    BSFixedString Name_20;
    char _pad_28[8];
    NiTexture* Previous_30;
    NiTexture* Next_38;
    char _pad_40[16];
    unsigned char TextureFlags_50;
    char _pad_51[7];
};
static_assert(sizeof(NiSourceTexture) == 88, "NiSourceTexture layout differs from the PDB");
