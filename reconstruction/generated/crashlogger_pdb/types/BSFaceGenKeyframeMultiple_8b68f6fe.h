// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenKeyframeMultiple; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFaceGenKeyframe.h"
struct BSFaceGenKeyframeMultiple_8b68f6fe {
    BSFaceGenKeyframe _base;
    float* values;
    unsigned int count;
    bool isUpdated;
    unsigned char pad1D;
    unsigned short pad1E;
};
static_assert(sizeof(BSFaceGenKeyframeMultiple_8b68f6fe) == 32, "BSFaceGenKeyframeMultiple_8b68f6fe layout differs from the PDB");
