// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2500f0 TESRegionDataGrass::~TESRegionDataGrass
// Adapted bodies: TESRegionDataGrass::~TESRegionDataGrass follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataGrass.cpp:28
#include "TESRegionDataGrass_2500f0.h"

// The constructor emits this class's vftable and deleting destructor.
TESRegionDataGrass::TESRegionDataGrass() = default;

TESRegionDataGrass::~TESRegionDataGrass()
{
    if (pObjects)
        delete pObjects;
}
