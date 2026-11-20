// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FormatPrefs; size 0x10
#pragma once

#include "AlphaFormat.h"
#include "MipFlag.h"
#include "PixelLayout.h"
struct FormatPrefs {
    PixelLayout pixelLayout;
    AlphaFormat alphaFormat;
    MipFlag mipMapped;
    unsigned int pad0C;
};
static_assert(sizeof(FormatPrefs) == 16, "FormatPrefs layout differs from the PDB");
