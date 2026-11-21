// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceShaderParam; size 0x80
#pragma once

#include "ImageSpaceEffectParam.h"
#include "NiTObjectArray_RE__NiPointer_RE__NiTexture_c9ae293f.h"
#include "NiTPrimitiveArray_RE__BSGraphics__TextureFilterMode_2108bd6d.h"
struct ImageSpaceShaderParam {
    ImageSpaceEffectParam _base;
    unsigned int unk08;
    bool SLIMode;
    unsigned char pad0D;
    unsigned short pad0E;
    unsigned long long unk10;
    unsigned long long unk18;
    unsigned char unk20;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int unk24;
    float unk28;
    unsigned int unk2C;
    float* vertexConstantGroup;
    unsigned int vertexConstantGroupSize;
    unsigned int unk3C;
    float* pixelConstantGroup;
    unsigned int pixelConstantGroupSize;
    unsigned int unk4C;
    NiTObjectArray_RE__NiPointer_RE__NiTexture_c9ae293f textures;
    NiTPrimitiveArray_RE__BSGraphics__TextureFilterMode_2108bd6d textureFilterModes;
};
static_assert(sizeof(ImageSpaceShaderParam) == 128, "ImageSpaceShaderParam layout differs from the PDB");
