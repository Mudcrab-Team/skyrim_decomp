// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTriShapeData; size 0x80
#pragma once

#include "NiBound_6900288c.h"
struct NiAdditionalGeometryData;
struct NiColorA_7eee66f4;
struct NiPoint2_6bdffc9f;
struct NiPoint3;
struct NiTriShapeData {
    char32_t* vftable;
    unsigned char _pad_8;
    unsigned char undefined_9[7];
    unsigned short vertices;
    unsigned short id;
    unsigned short dirtyFlags;
    unsigned short dataFlags;
    NiBound_6900288c bound;
    NiPoint3* vertex;
    NiPoint3* normal;
    NiColorA_7eee66f4* color;
    NiPoint2_6bdffc9f* texture;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    NiAdditionalGeometryData* additionalGeomData;
    unsigned char keepFlags;
    unsigned char compressFlags;
    unsigned char unk62;
    unsigned char unk63;
    unsigned char unk64;
    unsigned char unk65;
    bool hasGeoData;
    unsigned char unk67;
    unsigned short numTriangles;
    unsigned short activeTriangles;
    unsigned char undefined_6c[4];
    unsigned int triListLength;
    unsigned char undefined_74[4];
    unsigned short* triList;
};
static_assert(sizeof(NiTriShapeData) == 128, "NiTriShapeData layout differs from the PDB");
