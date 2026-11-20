// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ConvexPiece; size 0x50
#pragma once

#include "hkArray_unsigned_short_437647d0.h"
#include "hkVector4.h"
struct ConvexPiece {
    hkVector4 offset;
    hkArray_unsigned_short_437647d0 vertices;
    hkArray_unsigned_short_437647d0 faceVertices;
    hkArray_unsigned_short_437647d0 faceOffsets;
    unsigned short reference;
    unsigned short transformIndex;
    unsigned char pad44[12];
};
static_assert(sizeof(ConvexPiece) == 80, "ConvexPiece layout differs from the PDB");
