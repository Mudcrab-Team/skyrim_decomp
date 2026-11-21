// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEquipType; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct BGSEquipSlot_15bd99b3;
struct BGSEquipType {
    BaseFormComponent _base;
    BGSEquipSlot_15bd99b3* equipSlot;
};
static_assert(sizeof(BGSEquipType) == 16, "BGSEquipType layout differs from the PDB");
