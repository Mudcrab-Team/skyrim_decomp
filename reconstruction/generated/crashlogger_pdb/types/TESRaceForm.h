// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRaceForm; size 0x10
#pragma once

#include "BaseFormComponent.h"
struct TESRace;
struct TESRaceForm {
    BaseFormComponent _base;
    TESRace* race;
};
static_assert(sizeof(TESRaceForm) == 16, "TESRaceForm layout differs from the PDB");
