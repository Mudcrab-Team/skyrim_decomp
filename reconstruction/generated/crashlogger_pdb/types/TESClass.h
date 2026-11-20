// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESClass; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CLASS_DATA_ed5cf570.h"
#include "TESDescription_99869432.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
#include "TESTexture_fe82fffc.h"
struct TESClass {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESDescription_99869432 _base_TESDescription;
    TESTexture_fe82fffc _base_TESTexture;
    CLASS_DATA_ed5cf570 data;
    unsigned int pad74;
};
static_assert(sizeof(TESClass) == 120, "TESClass layout differs from the PDB");
