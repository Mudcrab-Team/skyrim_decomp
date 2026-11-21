// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TriShape; size 0x30
#pragma once

#include "VertexDesc.h"
struct ID3D11Buffer_63d37e24;
struct TriShape {
    ID3D11Buffer_63d37e24* vertexBuffer;
    ID3D11Buffer_63d37e24* indexBuffer;
    VertexDesc vertexDesc;
    unsigned int refCount;
    unsigned int pad1C;
    unsigned char* rawVertexData;
    unsigned short* rawIndexData;
};
static_assert(sizeof(TriShape) == 48, "TriShape layout differs from the PDB");
