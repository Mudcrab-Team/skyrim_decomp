// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSRenderPass; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSGeometry_5d16f03d;
struct BSLight;
struct BSShaderProperty;
struct BSShader_2c397dc3;
struct BSRenderPass {
    BSShader_2c397dc3* shader;
    BSShaderProperty* shaderProperty;
    BSGeometry_5d16f03d* geometry;
    unsigned int passEnum;
    unsigned char accumulationHint;
    unsigned char extraParam;
    unsigned char LODMode_raw;
    unsigned char numLights;
    unsigned char numShadowLights;
    unsigned char unk21;
    unsigned char undefined_22[2];
    unsigned int unk24;
    BSRenderPass* next;
    BSRenderPass* passGroupNext;
    BSLight** sceneLights;
    unsigned int cachePoolId;
    unsigned int pad44;
};
static_assert(sizeof(BSRenderPass) == 72, "BSRenderPass layout differs from the PDB");
