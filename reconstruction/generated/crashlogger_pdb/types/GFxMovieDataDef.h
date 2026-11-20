// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxMovieDataDef; size 0x48
#pragma once

#include "GFxResourceReport.h"
#include "GFxTimelineDef.h"
#include "GPtr_RE__GFxMovieDataDef__LoadTaskData_451e6544.h"
struct GFxResourceKey;
struct GFxMovieDataDef {
    GFxTimelineDef _base;
    GFxResourceReport _base_GFxResourceReport;
    GFxResourceKey* resourceKey;
    void* unk30;
    unsigned int fileFormat;
    unsigned int pad3C;
    GPtr_RE__GFxMovieDataDef__LoadTaskData_451e6544 loadTaskData;
};
static_assert(sizeof(GFxMovieDataDef) == 72, "GFxMovieDataDef layout differs from the PDB");
