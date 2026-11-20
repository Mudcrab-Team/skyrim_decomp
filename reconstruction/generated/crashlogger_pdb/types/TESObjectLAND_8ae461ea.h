// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLAND; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPointer_RE__QueuedFile_61648701.h"
#include "OBJ_LAND_e7df8cb4.h"
#include "TESChildCell.h"
#include "TESForm.h"
struct LoadedLandData;
struct TESObjectCELL_f81013b3;
struct TESObjectLAND_8ae461ea {
    TESForm _base;
    TESChildCell _base_TESChildCell;
    OBJ_LAND_e7df8cb4 data;
    unsigned int pad2C;
    TESObjectCELL_f81013b3* parentCell;
    NiPointer_RE__QueuedFile_61648701 queuedTextures;
    LoadedLandData* loadedData;
};
static_assert(sizeof(TESObjectLAND_8ae461ea) == 72, "TESObjectLAND_8ae461ea layout differs from the PDB");
