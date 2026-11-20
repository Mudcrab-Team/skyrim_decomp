// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadedAreaBound; size 0xa0
#pragma once

#include "NiPoint3.h"
#include "NiRefObject_f24a9221.h"
struct TESObjectCELL_f81013b3;
struct LoadedAreaBound {
    NiRefObject_f24a9221 _base;
    unsigned char neighborCells_raw[48];
    TESObjectCELL_f81013b3* cachedCell;
    unsigned char flags;
    unsigned char unk49[11];
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    void* bucketArray;
    unsigned char unk68[8];
    void* entries;
    NiPoint3 boundsMin;
    NiPoint3 boundsMax;
    float marginX;
    float marginY;
    float marginZ;
    float marginW;
};
static_assert(sizeof(LoadedAreaBound) == 160, "LoadedAreaBound layout differs from the PDB");
