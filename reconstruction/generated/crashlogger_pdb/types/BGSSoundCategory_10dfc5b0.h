// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundCategory; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "BSISoundCategory.h"
#include "Flag_a4a94b8a.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSSoundCategory_10dfc5b0 {
    TESForm _base;
    TESFullName _base_TESFullName;
    BSISoundCategory _base_BSISoundCategory;
    Flag_a4a94b8a flags;
    unsigned int unk3C;
    BGSSoundCategory_10dfc5b0* parentCategory;
    unsigned short unk48;
    unsigned short attenuation;
    unsigned short staticMult;
    unsigned short defaultMenuValue;
    float volumeMult;
    float frequencyMult;
};
static_assert(sizeof(BGSSoundCategory_10dfc5b0) == 88, "BGSSoundCategory_10dfc5b0 layout differs from the PDB");
