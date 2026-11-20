// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAllRayHitTempCollector; size 0x320
#pragma once

#include "hkInplaceArray_RE__hkpWorldRayCastOutput_8_98affe46.h"
#include "hkpRayHitCollector.h"
struct hkpAllRayHitTempCollector {
    hkpRayHitCollector _base;
    hkInplaceArray_RE__hkpWorldRayCastOutput_8_98affe46 hits;
};
static_assert(sizeof(hkpAllRayHitTempCollector) == 800, "hkpAllRayHitTempCollector layout differs from the PDB");
