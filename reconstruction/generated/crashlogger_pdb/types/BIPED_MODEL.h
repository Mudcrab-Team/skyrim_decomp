// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BIPED_MODEL; size 0x8
#pragma once

#include "ArmorType.h"
#include "BipedObjectSlot.h"
struct BIPED_MODEL {
    BipedObjectSlot bipedObjectSlots;
    ArmorType armorType;
};
static_assert(sizeof(BIPED_MODEL) == 8, "BIPED_MODEL layout differs from the PDB");
