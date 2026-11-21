// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESClass; size 0x78
// one of 2 different PDB types sharing this name
#pragma once

#include "CLASS_DATA.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
struct TESClass_b3a94e24 {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESDescription _base_TESDescription;
    TESTexture _base_TESTexture;
    CLASS_DATA data;
    unsigned int pad74;
};
static_assert(sizeof(TESClass_b3a94e24) == 120, "TESClass_b3a94e24 layout differs from the PDB");
