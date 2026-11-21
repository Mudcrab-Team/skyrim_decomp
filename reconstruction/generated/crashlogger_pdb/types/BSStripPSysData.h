// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSStripPSysData; size 0xc0
#pragma once

#include "NiPSysData.h"
struct StripData;
struct BSStripPSysData {
    NiPSysData _base;
    StripData* stripData;
    float unkB0;
    float unkB4;
    float pointLifetime;
    short maxPointCount;
    bool doZPrepass;
    unsigned char undefined_bf[1];
};
static_assert(sizeof(BSStripPSysData) == 192, "BSStripPSysData layout differs from the PDB");
