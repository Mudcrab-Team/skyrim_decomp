// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectARMA; size 0x178
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSBipedObjectForm__BipedData.h"
#include "BSTArray_TESRace_e2dbea85.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESModelTextureSwap.h"
#include "TESObjectARMA__Data.h"
struct BGSArtObject;
struct BGSBipedObjectForm__VFTable;
struct BGSFootstepSet;
struct BGSListForm_bac89fb1;
struct BGSTextureSet_d8b0e61f;
struct TESObjectARMA__VFTable;
struct TESRaceForm__VFTable;
struct TESRace_e57679c0;
struct TESObjectARMA {
    TESObjectARMA__VFTable* vftable_TESObjectARMA_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESRaceForm__VFTable* vftable_TESRaceForm_20;
    TESRace_e57679c0* Race_28;
    BGSBipedObjectForm__VFTable* vftable_BGSBipedObjectForm_30;
    BGSBipedObjectForm__BipedData ModelData_38;
    TESObjectARMA__Data ArmorAddonData_40;
    char _pad_4C[4];
    TESModelTextureSwap BipedModels_50[2];
    TESModelTextureSwap BipedModel1stPersons_C0[2];
    BGSTextureSet_d8b0e61f* SkinTextures_130[2];
    BGSListForm_bac89fb1* SkinTextureSwapLists_140[2];
    BSTArray_TESRace_e2dbea85 AdditionalRaces_150;
    BGSFootstepSet* FootstepSet_168;
    BGSArtObject* ArtObject_170;
};
static_assert(sizeof(TESObjectARMA) == 376, "TESObjectARMA layout differs from the PDB");
