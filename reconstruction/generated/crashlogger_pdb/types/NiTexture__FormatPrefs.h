// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTexture::FormatPrefs; size 0x10
#pragma once

#include "NiTexture__FormatPrefs__AlphaFormat.h"
#include "NiTexture__FormatPrefs__MipFlag.h"
#include "NiTexture__FormatPrefs__PixelLayout.h"
struct NiTexture__FormatPrefs {
    NiTexture__FormatPrefs__PixelLayout pixelLayout;
    NiTexture__FormatPrefs__AlphaFormat alphaFormat;
    NiTexture__FormatPrefs__MipFlag mipMapped;
    char _pad_C[4];
};
static_assert(sizeof(NiTexture__FormatPrefs) == 16, "NiTexture__FormatPrefs layout differs from the PDB");
