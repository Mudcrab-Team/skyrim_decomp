// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSRagdoll; size 0x1b8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSRagdoll__VFTable;
struct BSResource__ID;
struct TESModel__VFTable;
struct BGSRagdoll {
    BGSRagdoll__VFTable* vftable_BGSRagdoll_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESModel__VFTable* vftable_TESModel_20;
    BSFixedString ModelName_28;
    BSResource__ID* Textures_30;
    void* Addons_38;
    unsigned short NumTextures_40;
    unsigned short NumAddons_42;
    unsigned char undefined_44[4];
    unsigned long long unk048;
    unsigned char undefined_50[360];
};
static_assert(sizeof(BGSRagdoll) == 440, "BGSRagdoll layout differs from the PDB");
