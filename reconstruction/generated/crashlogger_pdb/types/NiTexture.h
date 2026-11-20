// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTexture; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiTexture__FormatPrefs.h"
struct NiTexture__VFTable;
struct NiTexture {
    NiTexture__VFTable* vftable_NiTexture_0;
    char _pad_8[8];
    NiTexture__FormatPrefs Format_10;
    BSFixedString Name_20;
    char _pad_28[8];
    NiTexture* Previous_30;
    NiTexture* Next_38;
};
static_assert(sizeof(NiTexture) == 64, "NiTexture layout differs from the PDB");
