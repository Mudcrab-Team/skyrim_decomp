// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSScaleformExternalTexture; size 0x18
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiPointer_RE__NiTexture_277bfefd.h"
struct BSScaleformExternalTexture {
    NiPointer_RE__NiTexture_277bfefd gamebryoTexture;
    unsigned int renderTarget;
    unsigned int pad0C;
    BSFixedString_char_83b572b4 filePath;
};
static_assert(sizeof(BSScaleformExternalTexture) == 24, "BSScaleformExternalTexture layout differs from the PDB");
