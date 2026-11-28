// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2599b0::Obj2599b0, treated as adapted: shaped like TESRegionPointList::TESRegionPointList in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.cpp:293
// SPDX-License-Identifier: CC0-1.0
// 0x2599b0 Obj2599b0::Obj2599b0
#include "Obj2599b0.h"

#include <cfloat>

// Initialize empty list pointers, bounding box extremes, and default flags.
Obj2599b0::Obj2599b0(bool a_flag)
    : unk00(nullptr),
      unk08(nullptr),
      unk10(nullptr),
      flag(a_flag),
      unk2C(0x400),
      unk30(0)
{
    minX = minY = FLT_MAX;
    maxX = maxY = -FLT_MAX;
}
