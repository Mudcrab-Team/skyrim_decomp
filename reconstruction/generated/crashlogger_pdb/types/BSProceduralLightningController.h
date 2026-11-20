// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSProceduralLightningController; size 0x190
#pragma once

#include "BSTEventSource_RE__BSProceduralGeomEvent_281d9705.h"
#include "BSTaskletGroup.h"
#include "NiInterpController_473343fb.h"
#include "NiPointer_RE__BSDynamicTriShape_6ab4c786.h"
struct BSProceduralLightningTasklet;
struct BSProceduralLightningController {
    NiInterpController_473343fb _base;
    BSTEventSource_RE__BSProceduralGeomEvent_281d9705 _base_BSTEventSource_RE_BSProceduralGeomEvent_;
    NiPointer_RE__BSDynamicTriShape_6ab4c786 geometry;
    unsigned char padA8[44];
    float cachedBounds[4];
    unsigned char padE4[36];
    unsigned char interpolators_raw[72];
    unsigned char pad150[24];
    float duration;
    float progress;
    unsigned char pad170[2];
    bool needsRegeneration;
    bool regenerationSkipped;
    unsigned char pad174[4];
    BSTaskletGroup taskGroupHandle;
    BSProceduralLightningTasklet* tasklet;
    bool interpolator0EventCache;
    bool interpolator1EventCache;
    unsigned char pad18A[6];
};
static_assert(sizeof(BSProceduralLightningController) == 400, "BSProceduralLightningController layout differs from the PDB");
