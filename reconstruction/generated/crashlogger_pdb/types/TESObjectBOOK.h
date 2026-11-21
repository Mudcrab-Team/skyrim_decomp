// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectBOOK; size 0x138
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSMessageIcon_87c00b71.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "OBJ_BOOK.h"
#include "TESBoundObject_fc790793.h"
#include "TESDescription.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct TESObjectSTAT;
struct TESObjectBOOK {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    TESValueForm _base_TESValueForm;
    TESWeightForm _base_TESWeightForm;
    TESDescription _base_TESDescription;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    OBJ_BOOK data;
    TESObjectSTAT* inventoryModel;
    TESDescription itemCardDescription;
};
static_assert(sizeof(TESObjectBOOK) == 312, "TESObjectBOOK layout differs from the PDB");
