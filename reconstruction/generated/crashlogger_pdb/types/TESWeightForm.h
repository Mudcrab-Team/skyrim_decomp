// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWeightForm; size 0x10
#pragma once

#include "BaseFormComponent.h"
struct TESWeightForm {
    BaseFormComponent _base;
    float weight;
    unsigned int pad0C;
};
static_assert(sizeof(TESWeightForm) == 16, "TESWeightForm layout differs from the PDB");
