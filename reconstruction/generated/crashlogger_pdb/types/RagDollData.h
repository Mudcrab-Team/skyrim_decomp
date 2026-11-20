// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RagDollData; size 0x20
#pragma once

#include "NiPoint3.h"
struct RagDollBone;
struct RagDollData {
    unsigned char boneCount;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    RagDollBone* bones;
    NiPoint3 bip01Rot;
    unsigned int pad1C;
};
static_assert(sizeof(RagDollData) == 32, "RagDollData layout differs from the PDB");
