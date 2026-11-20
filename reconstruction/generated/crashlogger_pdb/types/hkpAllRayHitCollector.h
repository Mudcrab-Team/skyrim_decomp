// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAllRayHitCollector; size 0x320
#pragma once

#include "hkInplaceArray_RE__hkpWorldRayCastOutput_8_98affe46.h"
#include "hkpRayHitCollector.h"
struct hkpAllRayHitCollector {
    hkpRayHitCollector _base;
    hkInplaceArray_RE__hkpWorldRayCastOutput_8_98affe46 hits;
};
static_assert(sizeof(hkpAllRayHitCollector) == 800, "hkpAllRayHitCollector layout differs from the PDB");
