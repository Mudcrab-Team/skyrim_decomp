// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RagDollBone; size 0x1c
#pragma once

#include "NiPoint3.h"
struct RagDollBone {
    unsigned char boneID;
    unsigned char pad01;
    unsigned short pad02;
    NiPoint3 bonePos;
    NiPoint3 boneRot;
};
static_assert(sizeof(RagDollBone) == 28, "RagDollBone layout differs from the PDB");
