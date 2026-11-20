// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSkinForm; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent.h"
struct TESObjectARMO_295db33a;
struct BGSSkinForm {
    BaseFormComponent _base;
    TESObjectARMO_295db33a* skin;
};
static_assert(sizeof(BGSSkinForm) == 16, "BGSSkinForm layout differs from the PDB");
