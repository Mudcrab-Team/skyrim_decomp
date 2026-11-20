// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShader; size 0x90
// one of 2 different PDB types sharing this name
#pragma once

#include "BSReloadShaderI.h"
#include "BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__PixelShader_RE_423cf88d.h"
#include "BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__VertexShader_RE_963bebd5.h"
#include "NiBoneMatrixSetterI_cb2536df.h"
#include "NiRefObject.h"
struct BSShader_2c397dc3 {
    NiRefObject _base;
    NiBoneMatrixSetterI_cb2536df _base_NiBoneMatrixSetterI;
    BSReloadShaderI _base_BSReloadShaderI;
    unsigned char shaderType_raw[8];
    BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__VertexShader_RE_963bebd5 vertexShaders;
    BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__PixelShader_RE_423cf88d pixelShaders;
    unsigned char* fxpFilename;
};
static_assert(sizeof(BSShader_2c397dc3) == 144, "BSShader_2c397dc3 layout differs from the PDB");
