// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESBipedModelForm; size 0xf0
#pragma once

#include "BaseFormComponent.h"
#include "TESModelRDT_2a63c2be.h"
struct TESBipedModelForm {
    BaseFormComponent _base;
    unsigned char worldModels_raw[112];
    unsigned char inventoryIcons_raw[32];
    unsigned char messageIcons_raw[48];
    TESModelRDT_2a63c2be constraintTemplate;
};
static_assert(sizeof(TESBipedModelForm) == 240, "TESBipedModelForm layout differs from the PDB");
