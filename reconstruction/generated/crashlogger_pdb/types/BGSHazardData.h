// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHazardData; size 0x38
#pragma once

#include "BGSHazardFlags.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSSoundDescriptorForm;
struct SpellItem_847bf892;
struct TESObjectLIGH_a35fc737;
struct BGSHazardData {
    unsigned int limit;
    float radius;
    float lifetime;
    float imageSpaceRadius;
    float targetInterval;
    BGSHazardFlags flags;
    SpellItem_847bf892* spell;
    TESObjectLIGH_a35fc737* light;
    BGSImpactDataSet_e1a4fffc* impactDataSet;
    BGSSoundDescriptorForm* sound;
};
static_assert(sizeof(BGSHazardData) == 56, "BGSHazardData layout differs from the PDB");
