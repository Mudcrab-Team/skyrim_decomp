// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLeafAnimNode; size 0x170
#pragma once

#include "BSFadeNode.h"
struct BSLeafAnimNode {
    BSFadeNode _base;
    float sqrDistanceToCamera;
    float leafAmplitudeRefr;
    float leafFrequency;
    float runningTime;
    float previousTimer;
    unsigned char undefined_16c[4];
};
static_assert(sizeof(BSLeafAnimNode) == 368, "BSLeafAnimNode layout differs from the PDB");
