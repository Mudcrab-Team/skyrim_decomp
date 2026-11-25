// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2522c0 TESRegionDataObjects::~TESRegionDataObjects
// Adapted bodies: TESRegionDataObjects::~TESRegionDataObjects follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataObjects.cpp:112
#include "TESRegionDataObjects_2522c0.h"

// The constructor emits this class's vftable and deleting destructor.
TESRegionDataObjects::TESRegionDataObjects() = default;

TESRegionDataObjects::~TESRegionDataObjects()
{
    delete pObjects;
}
