// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBipedObjectForm__BipedData; size 0x8
#pragma once

#include "BIPED_MODEL__ArmorType.h"
#include "BIPED_MODEL__BipedObjectSlot.h"
struct BGSBipedObjectForm__BipedData {
    BIPED_MODEL__BipedObjectSlot bipedObjectSlots;
    BIPED_MODEL__ArmorType armorType;
};
static_assert(sizeof(BGSBipedObjectForm__BipedData) == 8, "BGSBipedObjectForm__BipedData layout differs from the PDB");
