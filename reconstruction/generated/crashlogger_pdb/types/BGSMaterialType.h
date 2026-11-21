// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMaterialType; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "FLAG_92fc0a0b.h"
#include "MATERIAL_ID.h"
#include "NiColor_e5e1ad7d.h"
#include "TESForm.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSMaterialType {
    TESForm _base;
    BGSMaterialType* parentType;
    BSFixedString_char_83b572b4 materialName;
    MATERIAL_ID materialID;
    NiColor_e5e1ad7d materialColor;
    float buoyancy;
    FLAG_92fc0a0b flags;
    BGSImpactDataSet_e1a4fffc* havokImpactDataSet;
};
static_assert(sizeof(BGSMaterialType) == 80, "BGSMaterialType layout differs from the PDB");
