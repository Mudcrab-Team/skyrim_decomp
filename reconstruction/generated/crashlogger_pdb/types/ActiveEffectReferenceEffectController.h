// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffectReferenceEffectController; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3_a7124070.h"
#include "ReferenceEffectController_aa59977e.h"
struct ActiveEffect_7b2473e9;
struct ActiveEffectReferenceEffectController {
    ReferenceEffectController_aa59977e _base;
    ActiveEffect_7b2473e9* effect;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    NiPoint3_a7124070 windPoint;
};
static_assert(sizeof(ActiveEffectReferenceEffectController) == 32, "ActiveEffectReferenceEffectController layout differs from the PDB");
