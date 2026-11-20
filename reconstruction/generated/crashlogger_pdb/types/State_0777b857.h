// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: State; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct State_0777b857 {
    NiPointer_RE__NiSourceTexture_cf356212 defaultTextureProjNoiseMap;
    NiPointer_RE__NiSourceTexture_cf356212 defaultTextureProjDiffuseMap;
    NiPointer_RE__NiSourceTexture_cf356212 defaultTextureProjNormalMap;
    NiPointer_RE__NiSourceTexture_cf356212 defaultTextureProjNormalDetailMap;
    unsigned int unk20;
    unsigned int screenWidth;
    unsigned int screenHeight;
    unsigned int frameBufferViewport[2];
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk03C;
    unsigned int unk040;
    float projectionPosScaleX;
    float projectionPosScaleY;
    unsigned int frameCount;
    bool unk50;
    bool letterbox;
    bool unk052;
    bool compiledShaderThisFrame;
    bool insideFrame;
    bool useEarlyZ;
    unsigned char undefined_56[2];
};
static_assert(sizeof(State_0777b857) == 88, "State_0777b857 layout differs from the PDB");
