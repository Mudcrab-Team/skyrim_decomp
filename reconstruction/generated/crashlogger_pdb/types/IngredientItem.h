// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IngredientItem; size 0x140
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "GameData.h"
#include "MagicItem_34516af4.h"
#include "TESIcon_05686730.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct IngredientItem {
    MagicItem_34516af4 _base;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESIcon_05686730 _base_TESIcon;
    TESWeightForm _base_TESWeightForm;
    BGSEquipType _base_BGSEquipType;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    TESValueForm _base_TESValueForm;
    unsigned char data_raw[8];
    GameData gamedata;
    unsigned int pad13C;
};
static_assert(sizeof(IngredientItem) == 320, "IngredientItem layout differs from the PDB");
