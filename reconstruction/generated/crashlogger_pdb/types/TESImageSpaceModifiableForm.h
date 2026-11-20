// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifiableForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct TESImageSpaceModifier;
struct TESImageSpaceModifiableForm {
    BaseFormComponent _base;
    TESImageSpaceModifier* imageSpaceModifying;
};
static_assert(sizeof(TESImageSpaceModifiableForm) == 16, "TESImageSpaceModifiableForm layout differs from the PDB");
