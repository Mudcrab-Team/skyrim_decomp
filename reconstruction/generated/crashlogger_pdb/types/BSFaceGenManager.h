// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenManager; size 0x68
#pragma once

#include "BSFaceGenModelMap.h"
#include "BSTSingletonSDM_RE__BSFaceGenManager_ff1c58fe.h"
struct BSFaceGenManager {
    BSTSingletonSDM_RE__BSFaceGenManager_ff1c58fe _base;
    unsigned char undefined_1[3];
    unsigned int numActorsToMorph;
    bool emotions;
    unsigned char pad09[7];
    unsigned long long unk10;
    BSFaceGenModelMap modelMap;
    unsigned char isReset;
    unsigned char pad59[3];
    unsigned int unk5C;
    unsigned char unk60;
    unsigned char pad61[7];
};
static_assert(sizeof(BSFaceGenManager) == 104, "BSFaceGenManager layout differs from the PDB");
