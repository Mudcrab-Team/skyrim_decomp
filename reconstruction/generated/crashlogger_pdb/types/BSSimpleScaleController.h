// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSimpleScaleController; size 0x58
#pragma once

#include "NiTimeController_82cd7662.h"
struct BSSimpleScaleController {
    NiTimeController_82cd7662 _base;
    float scale3D;
    float refScale;
    float scaleAnimDuration;
    unsigned char undefined_54[4];
};
static_assert(sizeof(BSSimpleScaleController) == 88, "BSSimpleScaleController layout differs from the PDB");
