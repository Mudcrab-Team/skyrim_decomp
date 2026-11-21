// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActiveEffectReferenceEffectController; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3.h"
#include "ReferenceEffectController.h"
struct ActiveEffect;
struct ActiveEffectReferenceEffectController_d7a8df37 {
    ReferenceEffectController _base;
    ActiveEffect* effect;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    NiPoint3 windPoint;
};
static_assert(sizeof(ActiveEffectReferenceEffectController_d7a8df37) == 32, "ActiveEffectReferenceEffectController_d7a8df37 layout differs from the PDB");
