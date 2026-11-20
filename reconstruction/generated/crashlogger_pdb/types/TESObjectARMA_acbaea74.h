// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectARMA; size 0x178
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSBipedObjectForm.h"
#include "BSTArray_RE__TESRace_97670956.h"
#include "OBJ_ARMA.h"
#include "TESObject_2ec9fb8f.h"
#include "TESRaceForm.h"
struct BGSArtObject_14762d66;
struct BGSFootstepSet_a3d3259a;
struct BGSListForm;
struct BGSTextureSet;
struct TESObjectARMA_acbaea74 {
    TESObject_2ec9fb8f _base;
    TESRaceForm _base_TESRaceForm;
    BGSBipedObjectForm _base_BGSBipedObjectForm;
    OBJ_ARMA data;
    unsigned int pad04C;
    unsigned char bipedModels_raw[112];
    unsigned char bipedModel1stPersons_raw[112];
    BGSTextureSet* skinTextures[2];
    BGSListForm* skinTextureSwapLists[2];
    BSTArray_RE__TESRace_97670956 additionalRaces;
    BGSFootstepSet_a3d3259a* footstepSet;
    BGSArtObject_14762d66* artObject;
};
static_assert(sizeof(TESObjectARMA_acbaea74) == 376, "TESObjectARMA_acbaea74 layout differs from the PDB");
