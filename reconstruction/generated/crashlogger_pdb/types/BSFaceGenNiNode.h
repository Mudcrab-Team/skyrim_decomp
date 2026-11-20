// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenNiNode; size 0x190
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "NiMatrix3.h"
#include "NiPointer_RE__BSFaceGenAnimationData_a96eaaa2.h"
struct BSFaceGenNiNode {
    unsigned char _base_raw[336];
    NiMatrix3 baseRotation;
    unsigned int pad14C;
    NiPointer_RE__BSFaceGenAnimationData_a96eaaa2 animationData;
    float lastTime;
    BSPointerHandle_RE__Actor_1a35f4b9 unk15C;
    unsigned short flags;
    unsigned short pad162;
    unsigned int pad164;
};
static_assert(sizeof(BSFaceGenNiNode) == 400, "BSFaceGenNiNode layout differs from the PDB");
