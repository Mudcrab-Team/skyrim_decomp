// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectMISC; size 0x100
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSMessageIcon_87c00b71.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "TESBoundObject_fc790793.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct TESObjectMISC {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    TESValueForm _base_TESValueForm;
    TESWeightForm _base_TESWeightForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
};
static_assert(sizeof(TESObjectMISC) == 256, "TESObjectMISC layout differs from the PDB");
