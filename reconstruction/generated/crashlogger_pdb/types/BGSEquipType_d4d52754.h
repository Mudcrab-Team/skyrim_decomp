// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEquipType; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent_9d659514.h"
struct BGSEquipSlot;
struct BGSEquipType_d4d52754 {
    BaseFormComponent_9d659514 _base;
    BGSEquipSlot* equipSlot;
};
static_assert(sizeof(BGSEquipType_d4d52754) == 16, "BGSEquipType_d4d52754 layout differs from the PDB");
