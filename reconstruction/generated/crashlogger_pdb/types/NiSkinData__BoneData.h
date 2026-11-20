// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinData::BoneData; size 0x5c
#pragma once

#include "NiBound.h"
#include "NiTransform_333059e5.h"
struct NiSkinData__BoneVertData;
#pragma pack(push, 4)
struct NiSkinData__BoneData {
    NiTransform_333059e5 SkinToBone_0;
    NiBound Bound_34;
    char _pad_44[4];
    NiSkinData__BoneVertData* BoneVertData_48;
    unsigned short Verts_50;
    char _pad_52[6];
    unsigned char undefined_58[4];
};
#pragma pack(pop)
static_assert(sizeof(NiSkinData__BoneData) == 92, "NiSkinData__BoneData layout differs from the PDB");
