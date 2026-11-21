// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESAmmo; size 0x128
#pragma once

#include "AMMO_DATA.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSMessageIcon_87c00b71.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "BSFixedString_char_83b572b4.h"
#include "TESBoundObject_fc790793.h"
#include "TESDescription.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct TESAmmo {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    TESValueForm _base_TESValueForm;
    TESWeightForm _base_TESWeightForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    TESDescription _base_TESDescription;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    AMMO_DATA data;
    BSFixedString_char_83b572b4 shortDesc;
};
static_assert(sizeof(TESAmmo) == 296, "TESAmmo layout differs from the PDB");
