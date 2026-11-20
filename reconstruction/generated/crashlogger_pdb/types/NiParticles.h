// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiParticles; size 0x168
#pragma once

#include "BSGeometry.h"
#include "NiPointer_RE__NiPSysData_645ac08f.h"
struct NiParticles {
    BSGeometry _base;
    NiPointer_RE__NiPSysData_645ac08f particleData;
    unsigned long long unk160;
};
static_assert(sizeof(NiParticles) == 360, "NiParticles layout differs from the PDB");
