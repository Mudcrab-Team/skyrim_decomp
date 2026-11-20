// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingGoal; size 0x50
#pragma once

#include "BSPathingLocation.h"
#include "NiPoint3.h"
struct BSPathingGoal {
    NiPoint3 targetPoint;
    float targetAngleTolerance;
    BSPathingLocation location;
    float zDelta;
    float goalRadius;
    float normalizeSpeedAtGoal;
    unsigned char undefined_4c[4];
};
static_assert(sizeof(BSPathingGoal) == 80, "BSPathingGoal layout differs from the PDB");
