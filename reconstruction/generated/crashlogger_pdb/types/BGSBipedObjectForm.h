// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBipedObjectForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BIPED_MODEL.h"
#include "BaseFormComponent.h"
struct BGSBipedObjectForm {
    BaseFormComponent _base;
    BIPED_MODEL bipedModelData;
};
static_assert(sizeof(BGSBipedObjectForm) == 16, "BGSBipedObjectForm layout differs from the PDB");
