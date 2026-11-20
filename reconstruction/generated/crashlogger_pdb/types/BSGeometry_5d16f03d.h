// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGeometry; size 0x158
// one of 2 different PDB types sharing this name
#pragma once

#include "NiAVObject_968dc716.h"
#include "NiBound.h"
#include "NiPointer_RE__BSShaderProperty_1796b7db.h"
#include "NiPointer_RE__NiAlphaProperty_b810caf7.h"
#include "NiPointer_RE__NiSkinInstance_af94d754.h"
#include "VertexDesc.h"
struct TriShape;
struct BSGeometry_5d16f03d {
    NiAVObject_968dc716 _base;
    NiBound modelBound;
    NiPointer_RE__NiAlphaProperty_b810caf7 alphaProperty;
    NiPointer_RE__BSShaderProperty_1796b7db shaderProperty;
    NiPointer_RE__NiSkinInstance_af94d754 skinInstance;
    TriShape* rendererData;
    char32_t* unk140;
    VertexDesc vertexDesc;
    unsigned char type;
    unsigned char pad191;
    unsigned short pad192;
    unsigned int pad194;
};
static_assert(sizeof(BSGeometry_5d16f03d) == 344, "BSGeometry_5d16f03d layout differs from the PDB");
