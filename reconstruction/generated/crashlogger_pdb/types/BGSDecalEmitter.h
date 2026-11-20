// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDecalEmitter; size 0x18
#pragma once

#include "NiPointer_RE__BSTempEffectParticle_dae5fc70.h"
struct BGSImpactData;
struct BGSDecalEmitter {
    int unk00;
    bool unk04;
    bool pad05;
    unsigned short pad06;
    BGSImpactData* impactData;
    NiPointer_RE__BSTempEffectParticle_dae5fc70 particleEmitter;
};
static_assert(sizeof(BGSDecalEmitter) == 24, "BGSDecalEmitter layout differs from the PDB");
