// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShader; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSReloadShaderI_ae70fb91.h"
#include "BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__PixelShader_RE_423cf88d.h"
#include "BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__VertexShader_RE_963bebd5.h"
#include "NiBoneMatrixSetterI.h"
#include "NiRefObject_f24a9221.h"
struct BSShader {
    NiRefObject_f24a9221 _base;
    NiBoneMatrixSetterI _base_NiBoneMatrixSetterI;
    BSReloadShaderI_ae70fb91 _base_BSReloadShaderI;
    unsigned char shaderType_raw[8];
    BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__VertexShader_RE_963bebd5 vertexShaders;
    BSTScatterTable_RE__BSShaderTechniqueIDMap__HashPolicy_RE__BSGraphics__PixelShader_RE_423cf88d pixelShaders;
    unsigned char* fxpFilename;
};
static_assert(sizeof(BSShader) == 144, "BSShader layout differs from the PDB");
