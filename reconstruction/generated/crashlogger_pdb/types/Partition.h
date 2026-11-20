// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Partition; size 0x50
#pragma once

#include "VertexDesc.h"
struct TriShape;
struct Partition {
    VertexDesc vertexDesc;
    unsigned short* bones;
    float* weights;
    unsigned short* vertexMap;
    unsigned char* bonePalette;
    unsigned short* triList;
    unsigned short* stripLengths;
    unsigned short vertices;
    unsigned short triangles;
    unsigned short numBones;
    unsigned short strips;
    unsigned short bonesPerVertex;
    unsigned short pad42;
    float unk44;
    TriShape* buffData;
};
static_assert(sizeof(Partition) == 80, "Partition layout differs from the PDB");
