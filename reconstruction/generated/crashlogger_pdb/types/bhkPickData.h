// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkPickData; size 0xd0
#pragma once

#include "hkVector4.h"
#include "hkpWorldRayCastInput.h"
#include "hkpWorldRayCastOutput.h"
struct hkpAllRayHitCollector;
struct hkpAllRayHitTempCollector;
struct hkpClosestRayHitCollector;
struct bhkPickData {
    hkpWorldRayCastInput rayInput;
    hkpWorldRayCastOutput rayOutput;
    hkVector4 ray;
    unsigned char* aabbCache;
    hkpClosestRayHitCollector* closestRayHitCollector;
    hkpAllRayHitCollector* allRayHitCollector;
    hkpAllRayHitTempCollector* allRayHitTempCollector;
    bool pickFailed;
    unsigned char padC1;
    unsigned short padC2;
    unsigned int padC4;
    unsigned int padC8;
    unsigned char undefined_cc[4];
};
static_assert(sizeof(bhkPickData) == 208, "bhkPickData layout differs from the PDB");
