// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiParticleSystem; size 0x198
#pragma once

#include "NiParticles.h"
#include "NiTPointerList_RE__NiPointer_RE__NiPSysModifier_30a722c9.h"
struct NiParticleSystem {
    NiParticles _base;
    NiTPointerList_RE__NiPointer_RE__NiPSysModifier_30a722c9 modifierList;
    float unk180;
    float unk184;
    float unk188;
    float lastUpdate;
    bool resetSystem;
    bool dynamicBounds;
    bool isWorldspace;
    unsigned char pad193;
    unsigned int pad194;
};
static_assert(sizeof(NiParticleSystem) == 408, "NiParticleSystem layout differs from the PDB");
