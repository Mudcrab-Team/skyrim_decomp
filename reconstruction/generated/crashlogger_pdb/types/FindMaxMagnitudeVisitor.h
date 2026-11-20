// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FindMaxMagnitudeVisitor; size 0x18
#pragma once

#include "ForEachActiveEffectVisitor.h"
struct ActiveEffect;
struct FindMaxMagnitudeVisitor {
    ForEachActiveEffectVisitor _base;
    ActiveEffect* activeEffect;
    float maxMagnitude;
    unsigned char undefined_14[4];
};
static_assert(sizeof(FindMaxMagnitudeVisitor) == 24, "FindMaxMagnitudeVisitor layout differs from the PDB");
