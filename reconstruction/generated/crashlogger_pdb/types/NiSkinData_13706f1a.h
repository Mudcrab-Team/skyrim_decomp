// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinData; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiSkinPartition_ee1aac44.h"
struct BoneData;
struct NiSkinData_13706f1a {
    NiObject_de5bc370 _base;
    NiPointer_RE__NiSkinPartition_ee1aac44 skinPartition;
    unsigned char rootParentToSkin_raw[56];
    BoneData* boneData;
    unsigned int bones;
    unsigned int pad5C;
};
static_assert(sizeof(NiSkinData_13706f1a) == 96, "NiSkinData_13706f1a layout differs from the PDB");
