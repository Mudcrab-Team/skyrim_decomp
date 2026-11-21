// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NonActorMagicCaster; size 0x68
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "ExtraMagicCaster.h"
struct TESObjectREFR_b225f218;
struct NonActorMagicCaster {
    ExtraMagicCaster _base;
    TESObjectREFR_b225f218* unk58;
    BSPointerHandle_RE__Actor_1a35f4b9 blameActor;
    unsigned int unk64;
};
static_assert(sizeof(NonActorMagicCaster) == 104, "NonActorMagicCaster layout differs from the PDB");
