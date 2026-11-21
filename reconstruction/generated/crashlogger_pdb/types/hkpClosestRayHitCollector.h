// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpClosestRayHitCollector; size 0x70
#pragma once

#include "hkpRayHitCollector.h"
#include "hkpWorldRayCastOutput.h"
struct hkpClosestRayHitCollector {
    hkpRayHitCollector _base;
    hkpWorldRayCastOutput rayHit;
};
static_assert(sizeof(hkpClosestRayHitCollector) == 112, "hkpClosestRayHitCollector layout differs from the PDB");
