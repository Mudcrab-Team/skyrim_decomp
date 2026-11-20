// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AlchemyItem; size 0x168
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSMessageIcon_87c00b71.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "MagicItem_34516af4.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESWeightForm.h"
struct AlchemyItem_e992fb73 {
    MagicItem_34516af4 _base;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    BGSMessageIcon_87c00b71 _base_BGSMessageIcon;
    TESWeightForm _base_TESWeightForm;
    BGSEquipType _base_BGSEquipType;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    unsigned char data_raw[32];
    TESIcon_05686730 messageIcon;
};
static_assert(sizeof(AlchemyItem_e992fb73) == 360, "AlchemyItem_e992fb73 layout differs from the PDB");
