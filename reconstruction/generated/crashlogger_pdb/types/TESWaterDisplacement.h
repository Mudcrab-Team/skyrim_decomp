// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterDisplacement; size 0x30
#pragma once

#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiRefObject_f24a9221.h"
struct TESWaterForm_2ffdeaeb;
struct TESWaterDisplacement {
    NiRefObject_f24a9221 _base;
    TESWaterForm_2ffdeaeb* waterType;
    float waterHeight;
    unsigned int unk1C;
    unsigned int flags;
    unsigned int pad24;
    NiPointer_RE__NiAVObject_9e3aa701 displacementGeometry;
};
static_assert(sizeof(TESWaterDisplacement) == 48, "TESWaterDisplacement layout differs from the PDB");
