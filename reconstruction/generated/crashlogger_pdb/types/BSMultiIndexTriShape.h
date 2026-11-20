// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiIndexTriShape; size 0x1d8
#pragma once

#include "BSTriShape.h"
#include "NiColorA_7eee66f4.h"
#include "NiPointer_RE__BSShaderProperty_1796b7db.h"
#include "XMFLOAT4X4.h"
struct IndexBuffer;
struct BSMultiIndexTriShape {
    BSTriShape _base;
    IndexBuffer* altIndexBuffer;
    unsigned int altPrimCount;
    XMFLOAT4X4 materialProjection;
    unsigned int pad1AC;
    NiPointer_RE__BSShaderProperty_1796b7db additionalShaderProperty;
    unsigned char useAdditionalTriList;
    unsigned char pad1B9;
    unsigned short pad1BA;
    NiColorA_7eee66f4 materialParams;
    float materialScale;
    float normalDampener;
    unsigned int unk1D4;
};
static_assert(sizeof(BSMultiIndexTriShape) == 472, "BSMultiIndexTriShape layout differs from the PDB");
