// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLightingTemplate; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSDirectionalAmbientLightingColors_bbed7424.h"
#include "INTERIOR_DATA.h"
#include "TESForm.h"
struct BGSLightingTemplate {
    TESForm _base;
    INTERIOR_DATA data;
    BGSDirectionalAmbientLightingColors_bbed7424 directionalAmbientLightingColors;
};
static_assert(sizeof(BGSLightingTemplate) == 160, "BGSLightingTemplate layout differs from the PDB");
