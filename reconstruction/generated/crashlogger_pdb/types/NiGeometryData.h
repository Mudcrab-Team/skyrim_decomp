// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiGeometryData; size 0x68
#pragma once

#include "NiBound_6900288c.h"
#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiAdditionalGeometryData_412e6f5f.h"
struct NiColorA_7eee66f4;
struct NiPoint2_6bdffc9f;
struct NiPoint3;
struct NiGeometryData {
    NiObject_de5bc370 _base;
    unsigned short vertices;
    unsigned short id;
    unsigned short dirtyFlags;  // DirtyFlag in the PDB is wider than this slot
    unsigned short dataFlags;  // DataFlag in the PDB is wider than this slot
    NiBound_6900288c bound;
    NiPoint3* vertex;
    NiPoint3* normal;
    NiColorA_7eee66f4* color;
    NiPoint2_6bdffc9f* texture;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    NiPointer_RE__NiAdditionalGeometryData_412e6f5f additionalGeomData;
    unsigned char keepFlags;  // KeepFlag in the PDB is wider than this slot
    unsigned char compressFlags;  // CompressFlag in the PDB is wider than this slot
    unsigned char unk62;
    unsigned char unk63;
    unsigned char unk64;
    unsigned char unk65;
    bool hasGeoData;
    unsigned char unk67;
};
static_assert(sizeof(NiGeometryData) == 104, "NiGeometryData layout differs from the PDB");
