// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraGroupConstraint; size 0x48
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3.h"
struct ExtraGroupConstraint {
    BSExtraData_4ca6af76 _base;
    int constraintType;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 entityB;
    BSFixedString_char_83b572b4 attachNodeNameA;
    BSFixedString_char_83b572b4 attachNodeNameB;
    NiPoint3 constraintOffsetA;
    NiPoint3 constraintOffsetB;
    unsigned int originalCollisionGroupB;
    float dynamicMassScaleB;
};
static_assert(sizeof(ExtraGroupConstraint) == 72, "ExtraGroupConstraint layout differs from the PDB");
