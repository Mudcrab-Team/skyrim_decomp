// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGeometry; size 0x158
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiAVObject.h"
#include "NiBound_6900288c.h"
#include "NiPointer_RE__BSShaderProperty_1796b7db.h"
#include "NiPointer_RE__NiAlphaProperty_b810caf7.h"
#include "NiPointer_RE__NiSkinInstance_af94d754.h"
#include "VertexDesc.h"
struct TriShape;
struct BSGeometry {
    NiAVObject _base;
    NiBound_6900288c modelBound;
    NiPointer_RE__NiAlphaProperty_b810caf7 alphaProperty;
    NiPointer_RE__BSShaderProperty_1796b7db shaderProperty;
    NiPointer_RE__NiSkinInstance_af94d754 skinInstance;
    TriShape* rendererData;
    void* unk140;
    VertexDesc vertexDesc;
    unsigned char type;  // Type in the PDB is wider than this slot
    unsigned char pad151;
    unsigned short pad152;
    unsigned int pad154;
};
static_assert(sizeof(BSGeometry) == 344, "BSGeometry layout differs from the PDB");
