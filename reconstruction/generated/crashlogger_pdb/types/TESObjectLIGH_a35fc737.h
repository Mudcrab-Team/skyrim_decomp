// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLIGH; size 0x130
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSMessageIcon_87c00b71.h"
#include "NiColor_e5e1ad7d.h"
#include "OBJ_LIGH.h"
#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct BGSLensFlare;
struct BGSSoundDescriptorForm;
struct TESObjectLIGH_a35fc737 {
    TESBoundAnimObject _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    TESWeightForm _base_TESWeightForm;
    TESValueForm _base_TESValueForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSEquipType _base_BGSEquipType;
    OBJ_LIGH data;
    float fade;
    unsigned int pad10C;
    BGSSoundDescriptorForm* sound;
    NiColor_e5e1ad7d emittanceColor;
    unsigned int pad124;
    BGSLensFlare* lensFlare;
};
static_assert(sizeof(TESObjectLIGH_a35fc737) == 304, "TESObjectLIGH_a35fc737 layout differs from the PDB");
