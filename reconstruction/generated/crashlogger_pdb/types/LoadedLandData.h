// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadedLandData; size 0x49d0
#pragma once

#include "NiPoint2_6bdffc9f.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "hkpMoppCode.h"
struct NiNode;
struct TESLandTexture_448866c7;
struct LoadedLandData {
    NiNode* mesh[4];
    float heights[289][4];
    unsigned char percents[6][289][4];
    unsigned char colors[3][289][4];
    unsigned char normals_raw[3468];
    unsigned char geom_raw[32];
    NiPointer_RE__BSTriShape_e1b1b3c6 border;
    NiPoint2_6bdffc9f heightExtents;
    TESLandTexture_448866c7* defQuadTextures[4];
    TESLandTexture_448866c7* quadTextures[6][4];
    hkpMoppCode moppCode;
    unsigned long long unk49B0;
    unsigned long long unk49B8;
    unsigned long long unk49C0;
    unsigned long long unk49C8;
};
static_assert(sizeof(LoadedLandData) == 18896, "LoadedLandData layout differs from the PDB");
