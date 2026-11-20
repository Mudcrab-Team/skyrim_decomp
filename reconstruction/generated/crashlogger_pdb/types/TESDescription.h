// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESDescription; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLocalizedStringDL.h"
#include "BaseFormComponent.h"
struct TESDescription {
    BaseFormComponent _base;
    unsigned int fileOffset;
    BGSLocalizedStringDL descriptionText;
};
static_assert(sizeof(TESDescription) == 16, "TESDescription layout differs from the PDB");
