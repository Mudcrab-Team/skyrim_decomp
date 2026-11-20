// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Precipitation; size 0x90
#pragma once

#include "NiPointer_RE__BSGeometry_933f0714.h"
#include "OcclusionMapData.h"
struct Precipitation {
    unsigned long long __vftable;
    unsigned long long pad8;
    OcclusionMapData occlusionData;
    NiPointer_RE__BSGeometry_933f0714 currentPrecip;
    NiPointer_RE__BSGeometry_933f0714 lastPrecip;
    float lastCubeSize;
    float currentParticleDensity;
    float lastParticleDensity;
    unsigned int pad8C;
};
static_assert(sizeof(Precipitation) == 144, "Precipitation layout differs from the PDB");
