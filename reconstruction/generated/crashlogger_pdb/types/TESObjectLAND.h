// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLAND; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_QueuedFile_14ac7c8f.h"
#include "OBJ_LAND.h"
#include "TESFileContainer_70f0bdf4.h"
struct TESChildCell__VFTable;
struct TESObjectCELL;
struct TESObjectLAND__LoadedLandData;
struct TESObjectLAND__VFTable;
struct TESObjectLAND {
    TESObjectLAND__VFTable* vftable_TESObjectLAND_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESChildCell__VFTable* vftable_TESChildCell_20;
    OBJ_LAND data;
    unsigned int pad2C;
    TESObjectCELL* ParentCell_30;
    NiPointer_QueuedFile_14ac7c8f QueuedTextures_38;
    TESObjectLAND__LoadedLandData* loadedData_40;
};
static_assert(sizeof(TESObjectLAND) == 72, "TESObjectLAND layout differs from the PDB");
