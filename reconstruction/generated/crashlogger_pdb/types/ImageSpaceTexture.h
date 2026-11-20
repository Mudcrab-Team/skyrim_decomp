// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceTexture; size 0x20
#pragma once

#include "NiPointer_RE__NiSourceTexture_cf356212.h"
#include "TextureAddressMode.h"
#include "TextureFilterMode.h"
struct ImageSpaceTexture {
    NiPointer_RE__NiSourceTexture_cf356212 texture;
    unsigned char renderTarget_raw[4];
    unsigned int unk0C;
    TextureFilterMode filterMode;
    TextureAddressMode clampMode;
    bool isAcquired;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned short pad1C;
    unsigned char undefined_1e[2];
};
static_assert(sizeof(ImageSpaceTexture) == 32, "ImageSpaceTexture layout differs from the PDB");
