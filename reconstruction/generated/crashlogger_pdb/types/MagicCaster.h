// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicCaster; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__BSSoundHandle_5c88871c.h"
#include "State_675e5871.h"
struct MagicCaster_vtbl;
struct MagicItem_34516af4;
struct MagicCaster {
    MagicCaster_vtbl* __vftable;
    BSTArray_RE__BSSoundHandle_5c88871c sounds;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 desiredTarget;
    unsigned int pad24;
    MagicItem_34516af4* currentSpell;
    State_675e5871 state;
    float castingTimer;
    float currentSpellCost;
    float magnitudeOverride;
    float nextTargetUpdate;
    float projectileTimer;
};
static_assert(sizeof(MagicCaster) == 72, "MagicCaster layout differs from the PDB");
