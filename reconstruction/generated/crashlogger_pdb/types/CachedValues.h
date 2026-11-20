// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CachedValues; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__CachedValueData_d26db348.h"
#include "BooleanValue.h"
#include "Flags_fa7f7281.h"
struct CachedValues {
    float cachedRadius;
    float cachedWidth;
    float cachedLength;
    float cachedForwardLength;
    float cachedDPS;
    float cachedEyeLevel;
    float cachedWalkSpeed;
    float cachedRunSpeed;
    float cachedJogSpeed;
    float cachedFastWalkSpeed;
    BooleanValue booleanValues;
    Flags_fa7f7281 flags;
    BSTArray_RE__CachedValueData_d26db348 actorValueCache;
    BSTArray_RE__CachedValueData_d26db348 maxActorValueCache;
};
static_assert(sizeof(CachedValues) == 96, "CachedValues layout differs from the PDB");
