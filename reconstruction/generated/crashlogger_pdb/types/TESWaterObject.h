// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterObject; size 0x78
#pragma once

#include "BSTArray_RE__NiPointer_RE__BSMultiBoundAABB_3d534dea.h"
#include "NiPlane_4e79da03.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__TESWaterDisplacement_bde5c723.h"
#include "NiPointer_RE__TESWaterNormals_c085714d.h"
#include "NiPointer_RE__TESWaterReflections_3853d348.h"
#include "NiRefObject_f24a9221.h"
struct TESWaterForm_2ffdeaeb;
struct TESWaterObject {
    NiRefObject_f24a9221 _base;
    NiPlane_4e79da03 plane;
    NiPointer_RE__BSTriShape_e1b1b3c6 shape;
    NiPointer_RE__NiAVObject_9e3aa701 waterRippleObject;
    TESWaterForm_2ffdeaeb* waterType;
    unsigned long long unk38;
    NiPointer_RE__TESWaterReflections_3853d348 reflections;
    NiPointer_RE__TESWaterDisplacement_bde5c723 displacement;
    NiPointer_RE__TESWaterNormals_c085714d normals;
    BSTArray_RE__NiPointer_RE__BSMultiBoundAABB_3d534dea multiBounds;
    unsigned char flags;
    unsigned char pad71;
    unsigned short pad72;
    unsigned int pad74;
};
static_assert(sizeof(TESWaterObject) == 120, "TESWaterObject layout differs from the PDB");
