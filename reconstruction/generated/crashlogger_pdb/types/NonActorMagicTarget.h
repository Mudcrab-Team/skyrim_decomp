// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NonActorMagicTarget; size 0x40
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSSimpleList_RE__ActiveEffect_f55158cb.h"
#include "MagicTarget.h"
struct TESObjectREFR_b225f218;
struct NonActorMagicTarget {
    BSExtraData_4ca6af76 _base;
    MagicTarget _base_MagicTarget;
    TESObjectREFR_b225f218* targetObject;
    BSSimpleList_RE__ActiveEffect_f55158cb activeEffects;
};
static_assert(sizeof(NonActorMagicTarget) == 64, "NonActorMagicTarget layout differs from the PDB");
