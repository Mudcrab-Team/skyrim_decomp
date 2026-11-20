// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldRayCastOutput; size 0x60
#pragma once

#include "hkpShapeRayCastOutput.h"
struct hkpCollidable_9bd4f602;
struct hkpWorldRayCastOutput {
    hkpShapeRayCastOutput _base;
    hkpCollidable_9bd4f602* rootCollidable;
    unsigned long long pad58;
};
static_assert(sizeof(hkpWorldRayCastOutput) == 96, "hkpWorldRayCastOutput layout differs from the PDB");
