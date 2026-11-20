// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapePhantom; size 0x1a0
#pragma once

#include "hkMotionState.h"
#include "hkpPhantom_63a7c629.h"
struct hkpShapePhantom {
    hkpPhantom_63a7c629 _base;
    hkMotionState motionState;
};
static_assert(sizeof(hkpShapePhantom) == 416, "hkpShapePhantom layout differs from the PDB");
