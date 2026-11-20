// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLAND::LoadedLandData; size 0x49b0
#pragma once

#include "NiPoint2.h"
#include "NiPointer_BSTriShape_fcec8a37.h"
#include "TESObjectLAND__NormalData.h"
#include "hkpMoppCode_6965e29f.h"
struct TESLandTexture;
struct TESObjectLAND__LoadedLandData {
    float Heights_20[4][289];
    char Percents_1230[4][289][6];
    char Colors_2D48[4][289][3];
    TESObjectLAND__NormalData Normals_3AD4[4][289];
    NiPointer_BSTriShape_fcec8a37 GeometryShapes_4860[4];
    NiPointer_BSTriShape_fcec8a37 Border_4880;
    NiPoint2 HeightExtents_4888;
    TESLandTexture* DefQuadTextures_4890[4];
    TESLandTexture* QuadTextures_48B0[4][6];
    hkpMoppCode_6965e29f MoppCode_4970;
    char _pad_49B0[32];
};
static_assert(sizeof(TESObjectLAND__LoadedLandData) == 18864, "TESObjectLAND__LoadedLandData layout differs from the PDB");
