// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellItem; size 0xe8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSEquipType.h"
#include "BGSMenuDisplayObject.h"
#include "MagicItem_34516af4.h"
#include "TESDescription.h"
struct SpellItem_847bf892 {
    MagicItem_34516af4 _base;
    BGSEquipType _base_BGSEquipType;
    BGSMenuDisplayObject _base_BGSMenuDisplayObject;
    TESDescription _base_TESDescription;
    unsigned char data_raw[40];
};
static_assert(sizeof(SpellItem_847bf892) == 232, "SpellItem_847bf892 layout differs from the PDB");
