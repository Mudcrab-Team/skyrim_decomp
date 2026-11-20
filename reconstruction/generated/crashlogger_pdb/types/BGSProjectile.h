// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProjectile; size 0x138
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSDestructibleObjectForm_2db5e126.h"
#include "BGSPreloadable.h"
#include "BGSProjectileData.h"
#include "SOUND_LEVEL_ea79a10f.h"
#include "TESBoundObject.h"
#include "TESFullName_88f61e2a.h"
#include "TESModel.h"
struct BGSProjectile {
    TESBoundObject _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESModel _base_TESModel;
    BGSPreloadable _base_BGSPreloadable;
    BGSDestructibleObjectForm_2db5e126 _base_BGSDestructibleObjectForm;
    BGSProjectileData data;
    TESModel muzzleFlashModel;
    SOUND_LEVEL_ea79a10f soundLevel;
    unsigned int pad134;
};
static_assert(sizeof(BGSProjectile) == 312, "BGSProjectile layout differs from the PDB");
