// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TintMask; size 0x18
#pragma once

#include "Color_aa361e09.h"
struct TESTexture;
struct TintMask {
    TESTexture* texture;
    Color_aa361e09 color;
    float alpha;
    unsigned char type_raw[8];
};
static_assert(sizeof(TintMask) == 24, "TintMask layout differs from the PDB");
