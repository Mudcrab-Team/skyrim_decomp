// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCompressedMeshShapeData; size 0x100
#pragma once

#include "NiObject_de5bc370.h"
#include "hkAabb_e8754794.h"
#include "hkArray_RE__bhkMeshMaterial_77a80eb9.h"
#include "hkArray_RE__hkQsTransform_a439d864.h"
#include "hkArray_RE__hkVector4_8268593c.h"
#include "hkArray_RE__hkpCompressedMeshShape__BigTriangle_4a09e319.h"
#include "hkArray_RE__hkpCompressedMeshShape__Chunk_7b8e0088.h"
#include "hkArray_RE__hkpCompressedMeshShape__ConvexPiece_188f02fe.h"
#include "hkArray_RE__hkpNamedMeshMaterial_93b5a768.h"
#include "hkArray_unsigned_char_c72971e9.h"
#include "hkArray_unsigned_int_3dd3cd32.h"
#include "hkArray_unsigned_short_437647d0.h"
struct bhkCompressedMeshShapeData {
    NiObject_de5bc370 _base;
    int bitsPerIndex;
    int bitsPerWIndex;
    int wIndexMask;
    int indexMask;
    float error;
    unsigned int pad24;
    unsigned int pad28;
    unsigned int pad2C;
    hkAabb_e8754794 bounds;
    hkArray_unsigned_int_3dd3cd32 materials;
    hkArray_unsigned_short_437647d0 materials16;
    hkArray_unsigned_char_c72971e9 materials8;
    hkArray_RE__hkpNamedMeshMaterial_93b5a768 namedMaterials;
    hkArray_RE__bhkMeshMaterial_77a80eb9 meshMaterials;
    hkArray_RE__hkQsTransform_a439d864 transforms;
    hkArray_RE__hkpCompressedMeshShape__BigTriangle_4a09e319 bigTriangles;
    hkArray_RE__hkVector4_8268593c bigVertices;
    hkArray_RE__hkpCompressedMeshShape__Chunk_7b8e0088 chunks;
    hkArray_RE__hkpCompressedMeshShape__ConvexPiece_188f02fe convexPieces;
    unsigned char weldingType;  // WeldingType in the PDB is wider than this slot
    unsigned char materialType;  // MaterialType in the PDB is wider than this slot
    unsigned short padF2;
    unsigned int padF4;
    unsigned long long padF8;
};
static_assert(sizeof(bhkCompressedMeshShapeData) == 256, "bhkCompressedMeshShapeData layout differs from the PDB");
