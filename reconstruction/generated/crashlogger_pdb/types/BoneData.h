// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoneData; size 0x58
#pragma once

#include "NiBound_6900288c.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
struct BoneVertData;
struct BoneData {
    NiMatrix3 localBoneRotation;
    NiPoint3 worldBoneDir;
    unsigned int parentWorldBoneRotationIndex;
    NiBound_6900288c bound;
    unsigned int pad44;
    BoneVertData* boneVertData;
    unsigned short verts;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BoneData) == 88, "BoneData layout differs from the PDB");
