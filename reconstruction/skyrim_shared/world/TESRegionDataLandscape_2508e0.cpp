// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2508e0 TESRegionDataLandscape::~TESRegionDataLandscape
// Adapted bodies: TESRegionDataLandscape::~TESRegionDataLandscape follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataLandscape.cpp:33
#include "TESRegionDataLandscape_2508e0.h"

// The constructor emits this class's vftable and deleting destructor.
TESRegionDataLandscape::TESRegionDataLandscape() = default;

TESRegionDataLandscape::~TESRegionDataLandscape()
{
    if (icon)
        delete icon;
}
