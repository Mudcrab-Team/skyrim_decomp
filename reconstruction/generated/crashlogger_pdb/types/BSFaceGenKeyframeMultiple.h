// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenKeyframeMultiple; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFaceGenKeyframe_fa19db50.h"
struct BSFaceGenKeyframeMultiple {
    BSFaceGenKeyframe_fa19db50 _base;
    float* values;
    unsigned int count;
    bool isUpdated;
    unsigned char pad1D;
    unsigned short pad1E;
};
static_assert(sizeof(BSFaceGenKeyframeMultiple) == 32, "BSFaceGenKeyframeMultiple layout differs from the PDB");
