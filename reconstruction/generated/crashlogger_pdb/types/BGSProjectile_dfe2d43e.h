// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProjectile; size 0x138
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSPreloadable_c2823740.h"
#include "BGSProjectileData.h"
#include "SOUND_LEVEL.h"
#include "TESBoundObject_fc790793.h"
#include "TESFullName.h"
#include "TESModel_c52655e4.h"
struct BGSProjectile_dfe2d43e {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModel_c52655e4 _base_TESModel;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSProjectileData data;
    TESModel_c52655e4 muzzleFlashModel;
    SOUND_LEVEL soundLevel;
    unsigned int pad134;
};
static_assert(sizeof(BGSProjectile_dfe2d43e) == 312, "BGSProjectile_dfe2d43e layout differs from the PDB");
