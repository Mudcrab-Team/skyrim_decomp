// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESValueForm; size 0x10
#pragma once

#include "BaseFormComponent.h"
struct TESValueForm {
    BaseFormComponent _base;
    int value;
    unsigned int pad0C;
};
static_assert(sizeof(TESValueForm) == 16, "TESValueForm layout differs from the PDB");
