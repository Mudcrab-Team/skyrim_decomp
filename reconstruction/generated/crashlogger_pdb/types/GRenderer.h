// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRenderer; size 0x38
#pragma once

#include "GList_RE__GRendererEventHandler_1aa47173.h"
#include "GRefCountBase_RE__GRenderer_65_5d82489e.h"
#include "StereoDisplay.h"
#include "StereoParams.h"
struct GRenderer {
    GRefCountBase_RE__GRenderer_65_5d82489e _base;
    GList_RE__GRendererEventHandler_1aa47173 handlers;
    StereoParams s3DParams;
    StereoDisplay s3DDisplay;
};
static_assert(sizeof(GRenderer) == 56, "GRenderer layout differs from the PDB");
