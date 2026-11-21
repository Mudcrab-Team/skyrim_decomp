// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSImpactManager; size 0x58
#pragma once

#include "BSTEventSink_RE__BGSCollisionSoundEvent_6e0ab775.h"
#include "BSTEventSink_RE__BGSCombatImpactEvent_22b07c3b.h"
#include "BSTEventSink_RE__BGSFootstepEvent_59046107.h"
#include "BSTSingletonSDM_RE__BGSImpactManager_ab720918.h"
struct BGSImpactManager {
    BSTEventSink_RE__BGSFootstepEvent_59046107 _base;
    BSTEventSink_RE__BGSCombatImpactEvent_22b07c3b _base_BSTEventSink_RE_BGSCombatImpactEvent_;
    BSTEventSink_RE__BGSCollisionSoundEvent_6e0ab775 _base_BSTEventSink_RE_BGSCollisionSoundEvent_;
    BSTSingletonSDM_RE__BGSImpactManager_ab720918 _base_BSTSingletonSDM_RE_BGSImpactManager_;
    unsigned char undefined_19[63];
};
static_assert(sizeof(BGSImpactManager) == 88, "BGSImpactManager layout differs from the PDB");
