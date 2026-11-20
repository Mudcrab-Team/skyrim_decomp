// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReferenceEffect; size 0x48
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTempEffect.h"
struct ReferenceEffectController;
struct ReferenceEffect {
    BSTempEffect _base;
    ReferenceEffectController* controller;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 aimAtTarget;
    bool finished;
    bool ownController;
    unsigned short pad42;
    unsigned int pad44;
};
static_assert(sizeof(ReferenceEffect) == 72, "ReferenceEffect layout differs from the PDB");
