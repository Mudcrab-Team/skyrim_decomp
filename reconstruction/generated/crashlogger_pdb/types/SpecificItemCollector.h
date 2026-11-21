// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpecificItemCollector; size 0x80
#pragma once

#include "hkpClosestRayHitCollector.h"
struct SpecificItemCollector {
    hkpClosestRayHitCollector _base;
    unsigned char filter_raw[16];
};
static_assert(sizeof(SpecificItemCollector) == 128, "SpecificItemCollector layout differs from the PDB");
