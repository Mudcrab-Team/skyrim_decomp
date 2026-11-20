// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundCategory; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "Flag_d5bcd2af.h"
#include "TESFileContainer_70f0bdf4.h"
struct BSISoundCategory__VFTable;
struct TESFullName__VFTable;
struct BGSSoundCategory {
    unsigned char undefined_0[8];
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    BSISoundCategory__VFTable* vftable_BSISoundCategory_30;
    Flag_d5bcd2af flags;
    char _pad_3C[4];
    unsigned char undefined_40[8];
    unsigned short unk48;
    unsigned short attenuation;
    unsigned short staticMult;
    unsigned short DefaultMenuValue_4E;
    float volumeMult;
    float frequencyMult;
};
static_assert(sizeof(BGSSoundCategory) == 88, "BGSSoundCategory layout differs from the PDB");
