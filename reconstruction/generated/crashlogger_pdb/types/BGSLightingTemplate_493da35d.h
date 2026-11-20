// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLightingTemplate; size 0xa0
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDirectionalAmbientLightingColors.h"
#include "INTERIOR_DATA_9a5b4bee.h"
#include "TESForm_4074aa87.h"
struct BGSLightingTemplate_493da35d {
    TESForm_4074aa87 _base;
    INTERIOR_DATA_9a5b4bee data;
    BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;
};
static_assert(sizeof(BGSLightingTemplate_493da35d) == 160, "BGSLightingTemplate_493da35d layout differs from the PDB");
