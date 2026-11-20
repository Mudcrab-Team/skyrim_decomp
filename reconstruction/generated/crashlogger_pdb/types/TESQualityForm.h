// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESQualityForm; size 0x10
#pragma once

#include "BaseFormComponent.h"
#include "Quality.h"
struct TESQualityForm {
    BaseFormComponent _base;
    Quality quality;
    unsigned int pad0C;
};
static_assert(sizeof(TESQualityForm) == 16, "TESQualityForm layout differs from the PDB");
