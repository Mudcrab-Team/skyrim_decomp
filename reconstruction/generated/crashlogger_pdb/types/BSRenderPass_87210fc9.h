// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSRenderPass; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

struct BSGeometry;
struct BSLight_c6f6af80;
struct BSShader;
struct BSShaderProperty_a291ab3c;
struct BSRenderPass_87210fc9 {
    BSShader* shader;
    BSShaderProperty_a291ab3c* shaderProperty;
    BSGeometry* geometry;
    unsigned int passEnum;
    unsigned char accumulationHint;
    unsigned char extraParam;
    unsigned char LODMode[1];  // LODMode is 2 bytes in the PDB, more than this slot
    unsigned char numLights;
    unsigned char numShadowLights;
    unsigned char unk21;
    unsigned char undefined_22[2];
    unsigned int unk24;
    BSRenderPass_87210fc9* next;
    BSRenderPass_87210fc9* passGroupNext;
    BSLight_c6f6af80** sceneLights;
    unsigned int cachePoolId;
    unsigned int pad44;
};
static_assert(sizeof(BSRenderPass_87210fc9) == 72, "BSRenderPass_87210fc9 layout differs from the PDB");
